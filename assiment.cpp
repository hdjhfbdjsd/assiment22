#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

// 3-	Merge Filter 
using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char image3[SIZE][SIZE];
void loadImage ();
void loadImage2();

void saveImage ();
void doSomethingForImage ();

int main()
{
  loadImage2();
  loadImage();
  doSomethingForImage();
  saveImage();
  return 0;
}

//_________________________________________
void loadImage () {
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image);
}
//_________________________________________
void loadImage2 () {
   char image2FileName[100];

   // Get gray scale image file name
   cout << "Enter the source image2 file name: ";
   cin >> image2FileName;

   // Add to it .bmp extension and load image
   strcat (image2FileName, ".bmp");
   readGSBMP(image2FileName, image2);
}

//_________________________________________
void saveImage () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image3);
}

//_________________________________________
void doSomethingForImage() {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {

     image3[i][j] =(image[i][j] +image2[i][j]) /2;


    }
 
    
  }
}
