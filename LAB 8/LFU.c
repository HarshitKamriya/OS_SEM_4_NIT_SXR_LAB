#include<stdio.h>
#define MAX 100

int main(){
    int frames, pages, pageFaults = 0, pageHits = 0;
    int pageSequence[MAX];
    int frameArray[MAX];
    int frequency[MAX];
    
    printf("Enter number of frames: ");
    scanf("%d", &frames);
    
    printf("Enter number of pages: ");
    scanf("%d", &pages);
    
    printf("Enter page sequence: ");
    for(int i = 0; i < pages; i++){
        scanf("%d", &pageSequence[i]);
    }
    
    // Initialize frames
    for(int i = 0; i < frames; i++){
        frameArray[i] = -1;
        frequency[i] = 0;
    }
    
    printf("\nLFU (Least Frequently Used) Page Replacement:\n");
    printf("Page\tFrames\t\t\tStatus\n");
    printf("-----------------------------------------\n");
    
    int frameCount = 0;
    
    for(int i = 0; i < pages; i++){
        int page = pageSequence[i];
        int found = -1;
        
        // Check if page is in frame
        for(int j = 0; j < frames; j++){
            if(frameArray[j] == page){
                found = j;
                pageHits++;
                frequency[j]++;
                break;
            }
        }
        
        if(found == -1){
            pageFaults++;
            
            if(frameCount < frames){
                // Frame is not full
                frameArray[frameCount] = page;
                frequency[frameCount] = 1;
                frameCount++;
            }
            else{
                // Find page with minimum frequency
                int minFreq = frequency[0], minIndex = 0;
                for(int j = 1; j < frames; j++){
                    if(frequency[j] < minFreq){
                        minFreq = frequency[j];
                        minIndex = j;
                    }
                }
                frameArray[minIndex] = page;
                frequency[minIndex] = 1;
            }
        }
        
        printf("%d\t", page);
        for(int j = 0; j < frames; j++){
            if(frameArray[j] != -1)
                printf("%d ", frameArray[j]);
            else
                printf("- ");
        }
        printf("\t%s\n", found != -1 ? "HIT" : "MISS");
    }
    
    printf("\n-----------------------------------------\n");
    printf("Total Page Faults: %d\n", pageFaults);
    printf("Total Page Hits: %d\n", pageHits);
    printf("Page Fault Rate: %.2f%%\n", (pageFaults * 100.0) / pages);
    
    return 0;
}
