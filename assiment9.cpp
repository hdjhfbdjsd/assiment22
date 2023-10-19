// Program: demo2.cpp
// Purpose: Demonstrate use of bmplip for handling
//          bmp colored and grayscale images
//          Program load a gray image and store in another file
// Author:  Mohammad El-Ramly
// Date:    30 March 2018
// Version: 1.0
// mostsfa197khaled@gmail.com      Mostafa khaled mohamed fahim     ----> 20220422
// mhmwdhany132@gmail.com          Mahmoud Hany Mahmoud Abd Alhamed ----> 20221139
// mahmoudganafy66@gmail.com       Mahmoud Hanafy Mahmoud           ----> 20220316
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include"bmplib.h"
#include"bmplib.cpp"

using namespace std;
//unsigned char ans[SIZE][SIZE];
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];

void loadImage ();
void saveImage ();
void doSomethingForImage ();

void filter_blackwhilte(){
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {

            if (image[i][j]>120)
                image[i][j]=255;
            else
                image[i][j]=0;
        }
    }
}
void filter_invertImage() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            image[i][j] = 255 - image[i][j] ;}}
}
void filter_merge(){
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++){
            image[i][j] = (image[i][j]+image2[i][j])/2;
        }
    }
}

char t2;
void chooseflip(){
    cout<<"Flip (h)or(v) ?"<<"\n";
    cin>>t2;
}
void filter_flipvertical(){
    for(int j=0;j<SIZE;j++){
        for(int i=0;i<SIZE/2;i++){
            int x = image[j][i];
            image[j][i]= image[j][(SIZE-1)-i];
            image[j][(SIZE-1)-i]=x;

        }
    }
}
void filter_fliphortiotial(){
    for(int j=0; j < SIZE/2;++j){
        for(int i=0; i < SIZE;++i){

            char mg=image[j][i];
            image[j][i]=image[(SIZE-1)-j][i];
            image[(SIZE-1)-j][i]=mg;

        }
    }
}

// Assuming a 256x256 image size
// Function to rotate a grayscale image by a specified angle (90, 180, or 270 degrees)

void  filter_rotateImage() {

    unsigned char image1[SIZE][SIZE];

    int degree;
    cout << "enter degree";
    cin >> degree;
    if (degree == 90) {

        for (int i = 0; i < SIZE; i++) {
            for (int j = i + 1; j < SIZE; j++) {
                swap(image[i][j], image[j][i]);
            }
        }


    } else if (degree == 180) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0, K = SIZE - 1; j < K; j++, K--) {
                swap(image[j][i], image[K][i]);
            }
        }
    } else {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0, K = SIZE - 1; j < K; j++, K--) {
                swap(image[j][i], image[K][i]);

            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = i + 1; j < SIZE; j++) {
                swap(image[i][j], image[j][i]);
            }
        }
    }
}
char type;
void select_light(){
        cout<<" darken or lighten ?"<<"\n";
        cin>>type;

    }

void darkenimage() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            image[i][j] = image[i][j] /2 ;
        }
    }
}
void lightenimage() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            image[i][j] = (image[i][j])+((255-image[i][j])/2)  ;
        }
    }
}
void loadImage () {
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}
void loadImage2 () {
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, image2);
}

//_____
void saveimage () {
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}
//_____
void doSomethingForImage() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {

/* Example code to convert to BW the image
   A better version should NOt use 127 but the
   average of the pixels

        if (image[i][j] > 127)
            image[i][j] = 255;
        else
            image[i][j] = 0;sss
*/
// do something with the image
        }
    }
}
int main() {
    char key;
    cout<<"Ahlan ya user ya habibi "<<"\n";
    loadImage();

    while(true){
        cout<<"1- Black & White Filter\n"
              "2- Invert Filter\n"
              "3- Merge Filter \n"
              "4- Flip Image\n"
              "5- Darken and Lighten Image \n"
              "6- Rotate Image\n"
              "s- Save the image to a file\n"
              "0- Exit"<<"\n";
        cin>>key;
        if(key=='1'){
            filter_blackwhilte();
        }
        else if(key=='2'){

            filter_invertImage();

        }
        else if(key=='3'){
            loadImage2();
            filter_merge();

        }
        else if(key=='4') {
            chooseflip();
            if (t2 == 'h') {
                filter_fliphortiotial();

            } else {
                filter_flipvertical();

            }
        }
        else if(key=='5'){
            select_light();
            if(type=='l'){
                lightenimage();


            }
            else {

                darkenimage();

            }

        }
        else if(key=='6'){
            int degree;
            cin>>degree;
            filter_rotateImage();

        }
        else if(key=='s') saveimage();
        else break;
    }

}
