#include <estia-image.h>
#include <stdio.h>

#include "features.h"
#include "utils.h"

/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */

void helloWorld() {
    printf("Hello Tonio !");
}

void dimension (char *source_path) {
    unsigned char *data = NULL;
    int width = 0, height = 0, channel_count = 0;

    read_image_data(source_path, &data, &width, &height, &channel_count);
    printf("dimension: %d, %d\n", width, height);
}

void first_pixel(char *source_path) {
    unsigned char *data = NULL;
    int width = 0, height = 0, channel_count = 0;

    read_image_data(source_path, &data, &width, &height, &channel_count);
    int r = data[0];
    int g = data[1];
    int b = data[2];

    printf("first_pixel: %d, %d, %d\n", r, g, b);
}

void tenth_pixel (char *source_path) {
    unsigned char *data = NULL;
    int width = 0, height = 0, channel_count = 0;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    int index = 9 * channel_count;
    int r = data[index];
    int g = data[index + 1];
    int b = data[index + 2];

    printf("tenth_pixel: %d, %d, %d\n", r, g, b);
}

void second_line(char *source_path) {
    unsigned char *data = NULL;
    int width = 0, height = 0, channel_count = 0;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    int index = width * channel_count;
    int r = data[index];
    int g = data[index + 1];
    int b = data[index + 2];

    printf("second_line: %d, %d, %d\n", r, g, b);
}

void print_pixel( char *filename, int x, int y ) {
    unsigned char *data = NULL;
    int width = 0, height = 0, n = 0;
 
    read_image_data(filename, &data, &width, &height, &n);
 
    pixelRGB *px = get_pixel(data, width, height, n, x, y);
 
    printf("print_pixel (%d, %d): %d, %d, %d\n", x, y, px->R, px->G, px->B);
}