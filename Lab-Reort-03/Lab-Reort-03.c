#include <stdio.h>
#define MAX_FRAMES 10
#define MAX_PAGES 50
int main() {
    int frames[MAX_FRAMES], freq[MAX_FRAMES], time[MAX_FRAMES];
    int nFrames, nPages, pages[MAX_PAGES];
    int i, j, k, minFreq, minTime, pageFaults = 0, found, pos, counter = 0;
    printf("Enter number of frames: ");
    scanf("%d", &nFrames);
    printf("Enter number of pages: ");
    scanf("%d", &nPages);
    printf("Enter reference string: ");
    for(i = 0; i < nPages; i++) {
        scanf("%d", &pages[i]);
    }
    for(i = 0; i < nFrames; i++) {
        frames[i] = -1;
        freq[i] = 0;
        time[i] = 0;
    }
    printf("\nThe Page Replacement Process is ->\n");
    for(i = 0; i < nPages; i++) {
        found = 0;
        for(j = 0; j < nFrames; j++) {
            if(frames[j] == pages[i]) {
                freq[j]++;
                found = 1;
                break;
            }
        }
        if(found) {
            printf("For %d : No page fault!\n", pages[i]);
        } else {
            pageFaults++;
            for(j = 0; j < nFrames; j++) {
                if(frames[j] == -1) {
                    frames[j] = pages[i];
                    freq[j] = 1;
                    time[j] = counter++;
                    found = 1;
                    break;
                }
            }
            if(!found) {
                minFreq = freq[0];
                pos = 0;
                for(j = 1; j < nFrames; j++) {
                    if(freq[j] < minFreq || (freq[j] == minFreq && time[j] < time[pos])) {
                        minFreq = freq[j];
                        pos = j;
                    }
                }
                frames[pos] = pages[i];
                freq[pos] = 1;
                time[pos] = counter++;
            }
            printf("For %d : ", pages[i]);
            for(k = 0; k < nFrames; k++) {
                if(frames[k] != -1)
                    printf("%d ", frames[k]);
            }
            printf("\n");
        }
    }
    printf("\nTotal no of page faults using LFU is: %d\n", pageFaults);
    return 0;
}
