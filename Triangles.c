#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct{
  float coordinate[6];
  float perimetro;
  int isoscele;
  int scaleno;
  int equilatero;
}triangolo;

void update (triangolo *);
void perimetro(triangolo *);
triangolo * copia (triangolo);
void scrivi_file(FILE *, triangolo);

int main(int argc, char *argv[]){
  triangolo first, *second;
  FILE *output;
  output=fopen(argv[1],"w");
  update(&first);
  perimetro(&first);
  second=copia(first);
  scrivi_file(output,first);
  return 0;
}

void update(triangolo *rec){
  rec->isoscele = 0;
  rec->scaleno = 0;
  rec->equilatero= 0;
  for(int i=0; i<6; i++)
    scanf("%f", &(rec->coordinate[i]));
}

void perimetro(triangolo *rec){
  float lati[3];


  // Distanza tra due punti:
  // sqrt(x1-x2)^2 + (y1-y2)^2)
  lati[0] = sqrt(
               pow( rec->coordinate[0] - rec->coordinate[2], 2 )
            +  pow( rec->coordinate[1] - rec->coordinate[3], 2 )  );

  lati[1] = sqrt(
               pow( rec->coordinate[2] - rec->coordinate[4], 2 )
            +  pow( rec->coordinate[3] - rec->coordinate[5], 2 )  );

  lati[2] = sqrt(
               pow( rec->coordinate[4] - rec->coordinate[0], 2 )
            +  pow( rec->coordinate[5] - rec->coordinate[1], 2 )  );
  rec->perimetro=lati[0] + lati[1] + lati[2];

  if( lati[0] == lati[1] && lati[1] == lati[2])
    rec->equilatero = 1;
  else if(lati[0] == lati[1] || lati[1] == lati[2] || lati[0] == lati[2])
    rec->isoscele = 1;
  else
    rec->scaleno = 1;
}

triangolo * copia (triangolo rec){
  triangolo *copia = malloc(sizeof(triangolo));
  for(int i=0;i<6;i++){
    copia->coordinate[i]=rec.coordinate[i];
  }
  copia->perimetro=rec.perimetro;
  copia->isoscele=rec.isoscele;
  copia->equilatero=rec.equilatero;
  copia->scaleno=rec.scaleno;
  return copia;
}

void scrivi_file(FILE *F, triangolo rec){
  for(int i=0; i<6; i+=2){
    fprintf(F, "(%f, %f) ", rec.coordinate[i], rec.coordinate[i+1]);
  }
  fprintf(F, "%f %d %d %d", rec.perimetro, rec.isoscele, rec.scaleno, rec.equilatero);
}
