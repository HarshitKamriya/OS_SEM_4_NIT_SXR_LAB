#include<stdio.h>
#define MAX 100

int main(){
    int frames, pages, pageFaults = 0, pageHits = 0;
    int pageSequence[MAX], frameArray[MAX];
    int front = 0;
    
    printf("Enter number of frames: ");
    scanf("%d", &frames);
    
    printf("Enter number of pages: ");
    scanf("%d", &pages);
    
    printf("Enter page sequence: ");
    for(int i = 0; i < pages; i++){
        scanf("%d", &pageSequence[i]);
    }
    
    // Initialize frames with -1 (empty)
    for(int i = 0; i < frames; i++){
        frameArray[i] = -1;
    }
    
    printf("\nFIFO Page Replacement:\n");
    printf("Page\tFrames\t\t\tStatus\n");
    printf("-----------------------------------------\n");
    
    int nextSlot = 0;
    
    for(int i = 0; i < pages; i++){
        int page = pageSequence[i];
        int found = 0;
        
        // Check if page is already in frame
        for(int j = 0; j < frames; j++){
            if(frameArray[j] == page){
                found = 1;
                pageHits++;
                break;
            }
        }
        
        if(!found){
            pageFaults++;
            frameArray[nextSlot] = page;
            nextSlot = (nextSlot + 1) % frames;
        }
        
        printf("%d\t", page);
        for(int j = 0; j < frames; j++){
            if(frameArray[j] != -1)
                printf("%d ", frameArray[j]);
            else
                printf("- ");
        }
        printf("\t%s\n", found ? "HIT" : "MISS");
    }
    
    printf("\n-----------------------------------------\n");
    printf("Total Page Faults: %d\n", pageFaults);
    printf("Total Page Hits: %d\n", pageHits);
    printf("Page Fault Rate: %.2f%%\n", (pageFaults * 100.0) / pages);
    
    return 0;
}
