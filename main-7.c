// LaDarion Wells
#include <stdio.h>
#include "lodepng.h"
#include <string.h>

int main(){
    unsigned int error;
    unsigned char* rawImageBytes;
    unsigned int width, height;

// This function from lodepng will read in the image and fill in the bytes and size

    char filename[100] = "C:\\Users\\LaDar\\CLionProjects\\ArtGen3\\cookie.png";
    error = lodepng_decode32_file(&rawImageBytes, &width, &height, filename);
    if (error) {

        printf("error loading: %s\n", lodepng_error_text(error));
        return 1;
    }
    int arr[width][height];
    int x = 0;
    int y = 0;
    int red;
    int blue;
    int green;
    int i = 0;

    for(y = 0; y <= height-1; y++){ //loop for y
        for( x = 0; x <= width-1; x++){ // nested loop for x
            red = rawImageBytes[i];
            i++;
            green = rawImageBytes[i];
            i++;
            blue = rawImageBytes[i];
            int a; // alpha
            a = (red + blue + green) / 3;
            arr[x][y] = a;
            i = i + 2;
        }
    }

    int X =0;
    int s = 0;
    int Y = 0;
    int arr2[width / 5][height / 5];

    for (Y= 0; Y < height / 5; Y++){
        for (X= 0; X <width / 5; X++){
            for (int j = 0; j <= 4; j++){
                for(i = 0; i <= 4; i++){
                    s = arr[X * 5 + i][Y * 5 + j] + s; // Sum


                }
            }
            arr2[X][Y] = (s / 25);
            s = 0;
        }
    }

    char grayLevels[9] = {'@', '#', '8', '&', 'o', ':', '*', '.', ' '};
    for (Y = 0; Y <= height / 5; Y++){
        for (X= 0; X <= width / 5; X++){
            arr2[X][Y] = (arr2[X][Y] / 30);
            arr2[X][Y] = grayLevels[arr2[X][Y]];
            printf(" %c", arr2[X][Y]);
        }
        printf("\n");
    }
    return 0;
}

