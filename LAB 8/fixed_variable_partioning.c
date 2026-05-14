#include<stdio.h>
#define MAX 100

int main(){
    int totalMemory, choice;
    
    printf("===== Memory Partitioning =====\n");
    printf("1. Fixed Partitioning\n");
    printf("2. Variable Partitioning\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    if(choice == 1){
        // Fixed Partitioning
        printf("\n===== Fixed Partitioning =====\n");
        printf("Enter total memory size: ");
        scanf("%d", &totalMemory);
        
        int numPartitions;
        printf("Enter number of partitions: ");
        scanf("%d", &numPartitions);
        
        int partitionSize[MAX];
        int allocated[MAX];
        int process[MAX];
        
        for(int i = 0; i < numPartitions; i++){
            printf("Enter size of partition %d: ", i+1);
            scanf("%d", &partitionSize[i]);
            allocated[i] = 0;
            process[i] = -1;
        }
        
        int numProcesses;
        printf("Enter number of processes: ");
        scanf("%d", &numProcesses);
        
        printf("\nAllocating processes to partitions:\n");
        printf("Process\tSize\tAllocated to Partition\n");
        printf("----------------------------------------\n");
        
        for(int i = 0; i < numProcesses; i++){
            int size;
            printf("Enter size of process %d: ", i+1);
            scanf("%d", &size);
            
            int allocated_to = -1;
            for(int j = 0; j < numPartitions; j++){
                if(partitionSize[j] >= size && !allocated[j]){
                    allocated[j] = 1;
                    process[j] = i+1;
                    allocated_to = j+1;
                    break;
                }
            }
            
            if(allocated_to != -1){
                printf("%d\t%d\tPartition %d (Size: %d)\n", i+1, size, allocated_to, partitionSize[allocated_to-1]);
            }
            else{
                printf("%d\t%d\tNOT ALLOCATED\n", i+1, size);
            }
        }
        
        printf("\n\nPartition Status:\n");
        printf("Partition\tSize\tAllocated\tProcess\tWasted Space\n");
        printf("----------------------------------------------------------\n");
        for(int i = 0; i < numPartitions; i++){
            if(allocated[i]){
                printf("%d\t\t%d\tYes\t\tP%d\t-\n", i+1, partitionSize[i], process[i]);
            }
            else{
                printf("%d\t\t%d\tNo\t\t-\t%d\n", i+1, partitionSize[i], partitionSize[i]);
            }
        }
    }
    else if(choice == 2){
        // Variable Partitioning
        printf("\n===== Variable Partitioning (Dynamic) =====\n");
        printf("Enter total memory size: ");
        scanf("%d", &totalMemory);
        
        int allocated[MAX], processId[MAX];
        int startAddr[MAX], size[MAX];
        int numAllocations = 0;
        int usedMemory = 0;
        
        printf("Using First Fit strategy:\n\n");
        
        int numProcesses;
        printf("Enter number of processes: ");
        scanf("%d", &numProcesses);
        
        printf("\nAllocating processes:\n");
        printf("Process\tSize\tStart Address\tEnd Address\tStatus\n");
        printf("------------------------------------------------------\n");
        
        for(int i = 0; i < numProcesses; i++){
            int psize;
            printf("Enter size of process %d: ", i+1);
            scanf("%d", &psize);
            
            if(usedMemory + psize <= totalMemory){
                startAddr[numAllocations] = usedMemory;
                size[numAllocations] = psize;
                processId[numAllocations] = i+1;
                usedMemory += psize;
                
                printf("%d\t%d\t%d\t\t%d\t\tALLOCATED\n", i+1, psize, startAddr[numAllocations], startAddr[numAllocations] + psize - 1);
                numAllocations++;
            }
            else{
                printf("%d\t%d\t-\t\t-\t\tNOT ALLOCATED\n", i+1, psize);
            }
        }
        
        printf("\n\nMemory Layout:\n");
        printf("Address Range\t\tProcess\t\tSize\n");
        printf("------------------------------------------\n");
        for(int i = 0; i < numAllocations; i++){
            printf("%d - %d\t\tP%d\t\t%d\n", startAddr[i], startAddr[i] + size[i] - 1, processId[i], size[i]);
        }
        
        printf("\nMemory Statistics:\n");
        printf("Total Memory: %d\n", totalMemory);
        printf("Used Memory: %d\n", usedMemory);
        printf("Free Memory: %d\n", totalMemory - usedMemory);
        printf("Memory Utilization: %.2f%%\n", (usedMemory * 100.0) / totalMemory);
    }
    else{
        printf("Invalid choice!\n");
    }
    
    return 0;
}
