#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <pthread.h>

const int size = 1000;

unsigned char *image;

struct threadArg {
  pthread_mutex_t* mutex;
  unsigned char *image;
  int compteur;
};

static void calcul(int x, int y, unsigned char *pixel)
{
  long double p_x = (long double)x/size * 2.0l - 1.0l;
  long double p_y = (long double)y/size * 2.0l - 1.0l;
  long double tz = 0.7;
  long double zoo = powl(0.5l, 13.0l * tz);
  long double cc_x = -0.05l + p_x * zoo;
  long double cc_y = 0.6805l + p_y * zoo;
  long double z_x = 0.0l;
  long double z_y = 0.0l;
  long double m2 = 0.0l;
  long double co = 0.0l;
  long double dz_x = 0.0l;
  long double dz_y = 0.0l;
  int i;
  for (i = 0; i < 2560; i++)
  {
    long double old_dz_x, old_z_x;
    if (m2 > 1024.0l)
      continue;
    // Z' -> 2�Z�Z' + 1
    old_dz_x = dz_x;
    dz_x = 2.0l * z_x * dz_x - z_y * dz_y + 1.0l;
    dz_y = 2.0l * z_x * dz_y + z_y * old_dz_x;
    // Z -> Z� + c
    old_z_x = z_x;
    z_x = cc_x + z_x * z_x - z_y * z_y;
    z_y = cc_y + 2.0l * old_z_x * z_y;
    m2 = z_x * z_x + z_y * z_y;
    co += 1.0l;
  }
  // distance	
  // d(c) = |Z|�log|Z|/|Z'|
  long double d = 0.0l;
  if (co < 2560.0l)
  {
    long double dot_z = z_x * z_x + z_y * z_y;
    d = sqrtl(dot_z/(dz_x*dz_x+dz_y*dz_y)) * logl(dot_z);
    pixel[0] = fmodl(co,256.0l);
    d = 4.0l * d / zoo;
    if (d < 0.0l) d = 0.0l;
    if (d > 1.0l) d = 1.0l;
    pixel[1] = fmodl((1.0l-d) * 255.0l * 300.0l, 255.0l);
    d = powl(d, 50.0l*0.25l);
    pixel[2] = d * 255.0l;
  }
  else
    pixel[0]=pixel[1]=pixel[2]=0;
}

void *task(void* arg)
{
  struct threadArg* arguments = arg;
  int x, y;


  pthread_mutex_lock(arguments->mutex);
  while (arguments->compteur < 1000)
  {
    y = arguments->compteur;
    arguments->compteur = arguments->compteur + 1;
    pthread_mutex_unlock(arguments->mutex);
    for (x = 0; x < size; x++) {
      calcul(x, y, arguments->image+3*(y * size + x));
    }
    pthread_mutex_lock(arguments->mutex);
  } 
  pthread_mutex_unlock(arguments->mutex);


  return NULL; 
}

int main(int argc, char const *argv[])
{

  int N = atoi(argv[1]);

  FILE *file;

  image = malloc(3*size*size);

  struct threadArg arg;
  pthread_mutex_t mutex;
  pthread_mutex_init(&mutex,NULL);

  arg.mutex = &mutex;
  arg.image = image;
  arg.compteur = 0;

  pthread_t thread[N];
  for (int i=0; i < N; i++) {
    pthread_create(&thread[i],NULL,task,&arg);
  }

  for (int i=0; i < N; i++) {
    pthread_join(thread[i],NULL);
  }
  pthread_mutex_destroy(&mutex);
  
  // �criture fichier
  file = fopen("image.ppm", "w");
  fprintf(file, "P6\n%d %d\n255\n", size, size);
  fwrite(image, size, size * 3, file);
  fclose(file);
  free(image);


  return 0;
}
