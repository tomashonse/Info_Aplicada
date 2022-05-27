#include <stdio.h>
#include <stdlib.h>

typedef struct{
	unsigned char R, G, B; //componentes primarios de un color
} RGB;

typedef struct{
	int ancho, alto;
	RGB **pixel;
} ImagenRGB;

typedef unsigned char Gris;

typedef struct{
 int ancho, alto;
 Gris **pixel;
} ImagenGris;

ImagenRGB * creaImagenRGB( int ancho, int alto ){
	ImagenRGB *pi;
	pi=(ImagenRGB*)malloc(sizeof(ImagenRGB));
	pi->ancho=ancho;
	pi->alto=alto;
	pi->pixel=(RGB**)malloc(alto*sizeof(RGB*));
	for(int i=0;i<alto;i++){
		pi->pixel[i]=(RGB*)malloc(ancho*sizeof(RGB));
    }
	return pi;
}

ImagenGris * creaImagenGris( int ancho, int alto ){
    ImagenGris *image;
    image = (ImagenGris*)malloc(sizeof(ImagenGris));
    image->ancho = ancho;
    image->alto = alto;
    image->pixel = (Gris**)malloc(alto*sizeof(Gris*));
    for(int i = 0; i < alto; i++){
        image->pixel[i] = (Gris*)malloc(ancho*sizeof(Gris));
    }
    return image;
}

void setPixelRGB (ImagenRGB *im, int fila, int columna, RGB * pix){
	im->pixel[fila][columna].B = pix->B;
	im->pixel[fila][columna].R = pix->R;
	im->pixel[fila][columna].G = pix->G;
}

void setPixelGris( ImagenGris *im, int fila, int columna, Gris * pix ){
	im->pixel[fila][columna]=*pix;
}

RGB * getPixelRGB(ImagenRGB *im, int fila, int columna){
	return (&(im->pixel[fila][columna]));
}
Gris getPixelGris(ImagenGris *im, int fila, int columna){
	return im->pixel[fila][columna];
}

void destruyeImagenRGB(ImagenRGB * im){
	for(int i = 0; i < im->alto; i++){
		free(im->pixel[i]);
	}
	free(im->pixel);
	free(im);
}

void destruyeImagenGris(ImagenGris * im){
	for(int i = 0; i < im->alto; i++){
		free(im->pixel[i]);
	}
	free(im->pixel);
}

Gris RGBtoGris(RGB * pix){
	return  0.299*pix->R+0.587*pix->G+0.114*pix->B;
}

ImagenGris * transforma(ImagenRGB * im){
	int i,j;
	RGB *pix;
	Gris g;
	ImagenGris *pg=creaImagenGris(im->ancho,im->alto);
	for(i=0;i<pg->alto;i++)
		for(j=0;j<pg->ancho;j++){
			pix=getPixelRGB(im,i,j);
			g=RGBtoGris(pix);
			setPixelGris(pg,i,j,&g);
		}
	return pg;
}

int main(){
	ImagenRGB *p=creaImagenRGB(2,2);
	int i,j;
	RGB *q;
	RGB colores[]={{10,10,10},{20,20,20},{30,10,20},{10,20,30}};
	ImagenGris *pg;
	Gris g;
	for(i=0;i<2;i++)
		for(j=0;j<2;j++){
			setPixelRGB(p,i,j,&colores[i*2+j]);
			q=getPixelRGB(p,i,j);
			printf("El pixel %d,%d contiene %u de rojo, %u de verde, %u de azul\n",i+1,j+1,q->R,q->G,q->B);
		}

	printf("Transformo la imagen en una Gris\n");
	pg=transforma(p);
	for(i=0;i<2;i++)
		for(j=0;j<2;j++){
			g=getPixelGris(pg,i,j);
			printf("El pixel %d,%d contiene %u de gris\n",i+1,j+1,g);
		}
	return 0;
}
