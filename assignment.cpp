#include <stdio.h>
#include <math.h>

#define MAX_TOWERS 50

int towers[MAX_TOWERS][3];
int radius;

double distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int signal_quality(int x, int y, int i) {
    double d = distance(x, y, towers[i][0], towers[i][1]);
    return towers[i][2] / (1 + d);
}

int network_quality(int x, int y) {
    int quality = 0;
    for (int i = 0; i < MAX_TOWERS; i++) {
        if (towers[i][2] == 0) continue;
        double d = distance(x, y, towers[i][0], towers[i][1]);
        if (d <= radius) quality += signal_quality(x, y, i);
    }
    return quality;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &towers[i][0], &towers[i][1], &towers[i][2]);
    }
    scanf("%d", &radius);
    int max_quality = -1, max_x, max_y;
    for (int x = 0; x <= 50; x++) {
        for (int y = 0; y <= 50; y++) {
            int quality = network_quality(x, y);
            if (quality > max_quality) {
                max_quality = quality;
                max_x = x;
                max_y = y;
            }
        }
    }
    printf("%d %d\n", max_x, max_y);
    return 0;
}

