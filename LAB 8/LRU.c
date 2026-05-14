#include<stdio.h>
#define MAX 100

int main(){
    int frames, pages, pageFaults = 0, pageHits = 0;
    int pageSequence[MAX];
    int frameArray[MAX];
    int recentlyUsed[MAX];
    
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
        recentlyUsed[i] = -1;
    }
    
    printf("\nLRU (Least Recently Used) Page Replacement:\n");
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
                recentlyUsed[j] = i;
                break;
            }
        }
        
        if(found == -1){
            pageFaults++;
            
            if(frameCount < frames){
                // Frame is not full
                frameArray[frameCount] = page;
                recentlyUsed[frameCount] = i;
                frameCount++;
            }
            else{
                // Find least recently used page
                int minTime = recentlyUsed[0], minIndex = 0;
                for(int j = 1; j < frames; j++){
                    if(recentlyUsed[j] < minTime){
                        minTime = recentlyUsed[j];
                        minIndex = j;
                    }
                }
                frameArray[minIndex] = page;
                recentlyUsed[minIndex] = i;
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
