#include <stdio.h>
#include<math.h>
#define M_PI 3.14159265358979323846
#define Nu 398600.4
#define i 63.4
#define R 6378.0

int main() {
    float Vc;
    float Vi;
    float Va1;
    float Va2;
    float Va3;
    float We = 7.2921159;
    const float Hp1 = 500.0;
    const float Hp2 = 5500.0;
    const float Hp3 = 18000.0;
    int flag1 = 0;
    int flag2 = 0;
    int flag3 = 0;
    FILE *Vc_file = fopen("Vc_DATA.txt", "w");
    FILE *Vi_file = fopen("Vi_DATA.txt", "w");
    FILE *Va1_file = fopen("Va1_DATA.txt", "w");
    FILE *Va2_file = fopen("Va2_DATA.txt", "w");
    FILE *Va3_file = fopen("Va3_DATA.txt", "w");
    FILE *intersec = fopen("IntersectionPoints.txt", "w");

    for (int H = 1; H < 60001; H++) {
        Vc = sqrt(Nu / (R + H));
        Vi = We * pow(10, -5) * (R + H) * cos(i / 180.0 * M_PI);
        Va1 = sqrt((2 * Nu * (R + Hp1)) / ((R + H) * (R + H + R + Hp1)));
        Va2 = sqrt((2 * Nu * (R + Hp2)) / ((R + H) * (R + H + R + Hp2)));
        Va3 = sqrt((2 * Nu * (R + Hp3)) / ((R + H) * (R + H + R + Hp3)));

        if (Va1 < Vc && flag1 == 0) {
            for (float tmp = H - 2; tmp < H; tmp = tmp + 0.001) {
                Va1 = sqrt((2 * Nu * (R + Hp1)) / ((R + tmp) * (R + tmp + R + Hp1)));
                Vc = sqrt(Nu / (R + tmp));
                if (Va1 <= Vc) {
                    fprintf(intersec, "%f   %f\n", tmp, Vc);
                    break;
                }
            }
            flag1 = 1;
        }
        if (Va2 < Vc && flag2 == 0) {
            for (float tmp = H - 2; tmp < H; tmp = tmp + 0.001) {
                Va2 = sqrt((2 * Nu * (R + Hp2)) / ((R + tmp) * (R + tmp + R + Hp2)));
                Vc = sqrt(Nu / (R + tmp));
                if (Va2 <= Vc) {
                    fprintf(intersec, "%f   %f\n", tmp, Vc);
                    break;
                }
            }
            flag2 = 1;
        }
        if (Va3 < Vc && flag3 == 0) {
            for (float tmp = H - 2; tmp < H; tmp = tmp + 0.001) {
                Va3 = sqrt((2 * Nu * (R + Hp3)) / ((R + tmp) * (R + tmp + R + Hp3)));
                Vc = sqrt(Nu / (R + tmp));
                if (Va3 <= Vc) {
                    fprintf(intersec, "%f   %f\n", tmp, Vc);
                    break;
                }
            }
            flag3 = 1;
        }

        if (Va1 < Vi && flag1 == 1) {
            for (float tmp = H - 2; tmp < H; tmp = tmp + 0.01) {
                Va1 = sqrt((2 * Nu * (R + Hp1)) / ((R + tmp) * (R + tmp + R + Hp1)));
                Vi = We * pow(10, -5) * (R + tmp) * cos(i / 180.0 * M_PI);
                if (Va1 <= Vi) {
                    fprintf(intersec, "%f   %f\n", tmp, Vi);
                    break;
                }
            }
            flag1 = 2;
        }
        if (Va2 < Vi && flag2 == 1) {
            for (float tmp = H - 2; tmp < H; tmp = tmp + 0.01) {
                Va2 = sqrt((2 * Nu * (R + Hp2)) / ((R + tmp) * (R + tmp + R + Hp2)));
                Vi = We * pow(10, -5) * (R + tmp) * cos(i / 180.0 * M_PI);
                if (Va2 <= Vi) {
                    fprintf(intersec, "%f   %f\n", tmp, Vi);
                    break;
                }
            }
            flag2 = 2;
        }
        if (Va3 < Vi && flag3 == 1) {
            for (float tmp = H - 2; tmp < H; tmp = tmp + 0.01) {
                Va3 = sqrt((2 * Nu * (R + Hp3)) / ((R + tmp) * (R + tmp + R + Hp3)));
                Vi = We * pow(10, -5) * (R + tmp) * cos(i / 180.0 * M_PI);
                if (Va3 <= Vi) {
                    fprintf(intersec, "%f   %f\n", tmp, Vi);
                    break;
                }
            }
            flag3 = 2;
        }

        fprintf(Vc_file, "%i   %f \n", H, Vc);
        fprintf(Vi_file, "%i   %f \n", H, Vi);
        if (Va1 < Vc) {
            fprintf(Va1_file, "%i   %f\n", H, Va1);
        }
        
        if (Va2 < Vc) {
            fprintf(Va2_file, "%i   %f\n", H, Va2);
        }
        
        if (Va3 < Vc) {
            fprintf(Va3_file, "%i   %f\n", H, Va3);
        }
    }

    fclose(Vc_file);
    fclose(Vi_file);
    fclose(Va1_file);
    fclose(Va2_file);
    fclose(Va3_file);
    fclose(intersec);
    return 0;
}