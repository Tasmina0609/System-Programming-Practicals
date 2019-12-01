#include <stdio.h>

void sort_array (double *a, int nb_elem) {
    double temp=a[0];
    for(int i = 0; i < nb_elem; i++){
            while (a[i] > a[i+1]){
                temp = a[i+1];
                a[i+1] = a[i];
                a[i] = temp;
            }
        }
    }

int read_array (double *a, int max_elem, int *nb_elem) {
      for(int i=0;i<max_elem;i++) {
            nb_elem[i]=a[i];
      }
     sort_array (a,*nb_elem);
}



void display_array(double *array, int nb_elem) {
    for(int i = 0; i < nb_elem; i++) {
        printf("%lf  ", array[i]);
    }
    printf("\n");
}

int main () {
      double *array;
      int size;
      int *nb_elem=&size;
      printf("Total numbers: ");
      scanf("%d",nb_elem);

      printf("Enter numbers: ");
      for(int i=0;i<*nb_elem;i++)
              scanf("%lf",&array[i]);

      read_array (array,5, nb_elem);
      display_array(array,5);

}