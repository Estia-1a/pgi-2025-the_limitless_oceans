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

void max_pixel(char *source_path) {
    unsigned char *data = NULL;
    int largeur = 0, hauteur = 0, n = 0;
 
    read_image_data(source_path, &data, &largeur, &hauteur, &n);
 
    int somme_max = -1;
    int max_x = 0, max_y = 0;
    pixelRGB *p;
 
    for (int y = 0; y < hauteur; y++) {
        for (int x = 0; x < largeur; x++) {
            p = get_pixel(data, largeur, hauteur, n, x, y);
            int somme = p->R + p->G + p->B;
            if (somme > somme_max) {
                somme_max = somme;
                max_x = x;
                max_y = y;
            }
        }
    }
 
    p = get_pixel(data, largeur, hauteur, n, max_x, max_y);
    printf("max_pixel (%d, %d): %d, %d, %d\n", max_x, max_y, (int)p->R, (int)p->G, (int)p->B);
}

void min_pixel(char *source_path) {
    unsigned char *data = NULL;
    int largeur = 0, hauteur = 0, n = 0;
 
    read_image_data(source_path, &data, &largeur, &hauteur, &n);
 
    int somme_min = 256 * 3 + 1;
    int min_x = 0, min_y = 0;
    pixelRGB *p;
 
    for (int y = 0; y < hauteur; y++) {
        for (int x = 0; x < largeur; x++) {
            p = get_pixel(data, largeur, hauteur, n, x, y);
            int somme = p->R + p->G + p->B;
            if (somme < somme_min) {
                somme_min = somme;
                min_x = x;
                min_y = y;
            }
        }
    }
 
    p = get_pixel(data, largeur, hauteur, n, min_x, min_y);
    printf("min_pixel (%d, %d): %d, %d, %d\n", min_x, min_y, (int)p->R, (int)p->G, (int)p->B);
}

void max_component(char *source_path, char composante) {
    unsigned char *donnees = NULL;
    int largeur = 0, hauteur = 0, canaux = 0;

    read_image_data(source_path, &donnees, &largeur, &hauteur, &canaux);

    int max = -1;
    int x = 0, y = 0;

    for (int j = 0; j < hauteur; j++) {
        for (int i = 0; i < largeur; i++) {
            pixelRGB *pixel = get_pixel(donnees, largeur, hauteur, canaux, i, j);

            int valeur = 0;
            if (composante == 'R') {
                valeur = pixel->R;
            } else if (composante == 'G') {
                valeur = pixel->G;
            } else if (composante == 'B') {
                valeur = pixel->B;
            }

            if (valeur > max) {
                max = valeur;
                x = i;
                y = j;
            }
        }
    }

    printf("max_component %c (%d, %d): %d\n", composante, x, y, max);
}

void min_component(char *source_path, char composante) {
    unsigned char *data = NULL;
    int width = 0, height = 0, channel_count = 0;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    int min = 256;
    int x = 0, y = 0;

    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            pixelRGB *pixel = get_pixel(data, width, height, channel_count, i, j);

            int valeur = 0;
            if (composante == 'R') {
                valeur = pixel->R;
            } else if (composante == 'G') {
                valeur = pixel->G;
            } else if (composante == 'B') {
                valeur = pixel->B;
            }

            if (valeur < min) {
                min = valeur;
                x = i;
                y = j;
            }
        }
    }

    printf("min_component %c (%d, %d): %d\n", composante, x, y, min);
}

void stat_report(char *source_path) {
    unsigned char *data = NULL;
    int width = 0, height = 0, n = 0;
    read_image_data(source_path, &data, &width, &height, &n);
 
    FILE *fichier = fopen("stat_report.txt", "w");
 
    int max_somme = -1, x_max = 0, y_max = 0;
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            pixelRGB *pixel = get_pixel(data, width, height, n, i, j);
            int somme = pixel->R + pixel->G + pixel->B;
            if (somme > max_somme) {
                max_somme = somme;
                x_max = i;
                y_max = j;
            }
        }
    }
    fprintf(fichier, "max_pixel (%d, %d): %d, %d, %d\n\n", x_max, y_max,
            get_pixel(data, width, height, n, x_max, y_max)->R,
            get_pixel(data, width, height, n, x_max, y_max)->G,
            get_pixel(data, width, height, n, x_max, y_max)->B);
 
    int min_somme = 256 * 3 + 1, x_min = 0, y_min = 0;
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            pixelRGB *pixel = get_pixel(data, width, height, n, i, j);
            int somme = pixel->R + pixel->G + pixel->B;
            if (somme < min_somme) {
                min_somme = somme;
                x_min = i;
                y_min = j;
            }
        }
    }
    fprintf(fichier, "min_pixel (%d, %d): %d, %d, %d\n\n", x_min, y_min,
            get_pixel(data, width, height, n, x_min, y_min)->R,
            get_pixel(data, width, height, n, x_min, y_min)->G,
            get_pixel(data, width, height, n, x_min, y_min)->B);
 
    char composants[] = {'R', 'G', 'B'};
    for (int k = 0; k < 3; k++) {
        char c = composants[k];
        int val_max = -1, x = 0, y = 0;
        for (int j = 0; j < height; j++) {
            for (int i = 0; i < width; i++) {
                pixelRGB *pixel = get_pixel(data, width, height, n, i, j);
                int val = (c == 'R') ? pixel->R : (c == 'G') ? pixel->G : pixel->B;
                if (val > val_max) {
                    val_max = val;
                    x = i;
                    y = j;
                }
            }
        }
        fprintf(fichier, "max_component %c (%d, %d): %d\n\n", c, x, y, val_max);
    }
 
    for (int k = 0; k < 3; k++) {
        char c = composants[k];
        int val_min = 256, x = 0, y = 0;
        for (int j = 0; j < height; j++) {
            for (int i = 0; i < width; i++) {
                pixelRGB *pixel = get_pixel(data, width, height, n, i, j);
                int val = (c == 'R') ? pixel->R : (c == 'G') ? pixel->G : pixel->B;
                if (val < val_min) {
                    val_min = val;
                    x = i;
                    y = j;
                }
            }
        }
        fprintf(fichier, "min_component %c (%d, %d): %d\n\n", c, x, y, val_min);
    }
 
    fclose(fichier);
}

void color_red(char *source_path) {
    unsigned char *data = NULL;
    int width = 0, height = 0, channel_count = 0;
 
    read_image_data(source_path, &data, &width, &height, &channel_count);
 
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            pixelRGB *pixel = get_pixel(data, width, height, channel_count, i, j);
            pixel->G = 0;
            pixel->B = 0;
        }
    }
 
    write_image_data("image_out.bmp", data, width, height);
}

void color_green(char *source_path) {
    unsigned char *data = NULL;
    int width = 0, height = 0, channel_count = 0;
 
    read_image_data(source_path, &data, &width, &height, &channel_count);
 
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            pixelRGB *pixel = get_pixel(data, width, height, channel_count, i, j);
            pixel->R = 0;
            pixel->B = 0;
        }
    }
 
    write_image_data("image_out.bmp", data, width, height);
}

void color_blue(char *source_path) {
    unsigned char *data = NULL;
    int width = 0, height = 0, channel_count = 0;
 
    read_image_data(source_path, &data, &width, &height, &channel_count);
 
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            pixelRGB *pixel = get_pixel(data, width, height, channel_count, i, j);
            pixel->R = 0;
            pixel->G = 0;
        }
    }
 
    write_image_data("image_out.bmp", data, width, height);
}

void color_gray(char *source_path) {
    unsigned char *data = NULL;
    int width = 0, height = 0, channel_count = 0;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            pixelRGB *pixel = get_pixel(data, width, height, channel_count, i, j);
            unsigned char moyenne = (pixel->R + pixel->G + pixel->B) / 3;
            pixel->R = moyenne;
            pixel->G = moyenne;
            pixel->B = moyenne;
        }
    }

    write_image_data("image_out.bmp", data, width, height);
}

void color_invert(char *source_path) {
    unsigned char *data = NULL;
    int width = 0, height = 0, channel_count = 0;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            pixelRGB *pixel = get_pixel(data, width, height, channel_count, i, j);
            pixel->R = 255 - pixel->R;
            pixel->G = 255 - pixel->G;
            pixel->B = 255 - pixel->B;
        }
    }

    write_image_data("image_out.bmp", data, width, height);
}

void color_gray_luminance(char *source_path) {
    unsigned char *data = NULL;
    int width = 0, height = 0, channel_count = 0;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            pixelRGB *pixel = get_pixel(data, width, height, channel_count, i, j);
            unsigned char value = (unsigned char)(0.21 * pixel->R + 0.72 * pixel->G + 0.07 * pixel->B);
            pixel->R = value;
            pixel->G = value;
            pixel->B = value;
        }
    }

    write_image_data("image_out.bmp", data, width, height);
}

void color_desaturate(char *source_path) {
    unsigned char *data = NULL;
    int width = 0, height = 0, channel_count = 0;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            pixelRGB *pixel = get_pixel(data, width, height, channel_count, i, j);

            unsigned char min_val = pixel->R;
            if (pixel->G < min_val) min_val = pixel->G;
            if (pixel->B < min_val) min_val = pixel->B;

            unsigned char max_val = pixel->R;
            if (pixel->G > max_val) max_val = pixel->G;
            if (pixel->B > max_val) max_val = pixel->B;

            unsigned char new_val = (min_val + max_val) / 2;

            pixel->R = new_val;
            pixel->G = new_val;
            pixel->B = new_val;
        }
    }

    write_image_data("image_out.bmp", data, width, height);
}

void rotate_cw(char *source_path) {
    unsigned char *data = NULL;
    int width = 0, height = 0, channel_count = 0;
 
    read_image_data(source_path, &data, &width, &height, &channel_count);
 
    int new_width = height;
    int new_height = width;

    unsigned char *rotated_data = malloc(new_width * new_height * channel_count);
 
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            pixelRGB *src_pixel = get_pixel(data, width, height, channel_count, i, j);
            pixelRGB *dst_pixel = get_pixel(rotated_data, new_width, new_height, channel_count, height - 1 - j, i);
 
            dst_pixel->R = src_pixel->R;
            dst_pixel->G = src_pixel->G;
            dst_pixel->B = src_pixel->B;
        }
    }
 
    write_image_data("image_out.bmp", rotated_data, new_width, new_height);
}

void rotate_acw(char *source_path) {
    unsigned char *data = NULL;
    int width = 0, height = 0, channel_count = 0;
 
    read_image_data(source_path, &data, &width, &height, &channel_count);
 
    int new_width = height;
    int new_height = width;
 
    unsigned char *new_data = malloc(new_width * new_height * channel_count);
 
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            for (int c = 0; c < channel_count; c++) {

                int new_x = j;
                int new_y = width - 1 - i;
 
                new_data[(new_y * new_width + new_x) * channel_count + c] =
                    data[(j * width + i) * channel_count + c];
            }
        }
    }
 
    write_image_data("image_out.bmp", new_data, new_width, new_height);
}

void mirror_horizontal(char *source_path) {
    unsigned char *data = NULL;
    int width = 0, height = 0, channel_count = 0;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    unsigned char *new_data = malloc(width * height * channel_count);

    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            for (int c = 0; c < channel_count; c++) {
                new_data[(j * width + i) * channel_count + c] =
                    data[(j * width + (width - 1 - i)) * channel_count + c];
            }
        }
    }
    write_image_data("image_out.bmp", new_data, width, height);
}

void mirror_vertical(char *source_path) {
    unsigned char *data = NULL;
    int width = 0, height = 0, channel_count = 0;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    unsigned char *new_data = malloc(width * height * channel_count);

    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            for (int c = 0; c < channel_count; c++) {
                new_data[(j * width + i) * channel_count + c] =
                    data[((height - 1 - j) * width + i) * channel_count + c];
            }
        }
    }
    write_image_data("image_out.bmp", new_data, width, height);
}

void mirror_total(char *source_path) {
    unsigned char *data = NULL;
    int width = 0, height = 0, channel_count = 0;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    unsigned char *new_data = malloc(width * height * channel_count);

    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            for (int c = 0; c < channel_count; c++) {
                new_data[(j * width + i) * channel_count + c] =
                    data[((height - 1 - j) * width + (width - 1 - i)) * channel_count + c];
            }
        }
    }
    write_image_data("image_out.bmp", new_data, width, height);

}
void scale_crop(char *source_path, int center_x, int center_y, int crop_width, int crop_height) {
    unsigned char *data = NULL;
    int width = 0, height = 0, channel_count = 0;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    int start_x = center_x - crop_width / 2;
    int start_y = center_y - crop_height / 2;

    unsigned char *cropped_data = malloc(crop_width * crop_height * channel_count);

    for (int j = 0; j < crop_height; j++) {
        for (int i = 0; i < crop_width; i++) {
            int src_x = start_x + i;
            int src_y = start_y + j;

            for (int c = 0; c < channel_count; c++) {
                if (src_x >= 0 && src_x < width && src_y >= 0 && src_y < height) {
                    cropped_data[(j * crop_width + i) * channel_count + c] =
                        data[(src_y * width + src_x) * channel_count + c];
                } else {
                    // Remplir en noir si on sort de l'image
                    cropped_data[(j * crop_width + i) * channel_count + c] = 0;
                }
            }
        }
    }

    write_image_data("image_out.bmp", cropped_data, crop_width, crop_height);
}
