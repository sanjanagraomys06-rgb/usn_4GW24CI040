#include <stdio.h>
#include <string.h>

struct block {
    int size;
    int allocated;
    int process_id;
};

struct process {
    int pid;
    int size;
    int allocated;
    int block_no;
};

void resetBlocks(struct block blocks[], struct block original[], int num_blocks) {
    for (int i = 0; i < num_blocks; i++) {
        blocks[i].size = original[i].size;
        blocks[i].allocated = 0;
        blocks[i].process_id = -1;
    }
}

void resetProcesses(struct process processes[], int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        processes[i].allocated = 0;
        processes[i].block_no = -1;
    }
}

void firstFit(struct block blocks[], int num_blocks, 
              struct process processes[], int num_processes) {
    
    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < num_blocks; j++) {
            if (!blocks[j].allocated && blocks[j].size >= processes[i].size) {
                blocks[j].allocated = 1;
                blocks[j].process_id = processes[i].pid;
                processes[i].allocated = 1;
                processes[i].block_no = j + 1;
                break;
            }
        }
    }
}

void bestFit(struct block blocks[], int num_blocks, 
             struct process processes[], int num_processes) {
    
    for (int i = 0; i < num_processes; i++) {
        int best_idx = -1;
        int min_size = 9999;
        
        for (int j = 0; j < num_blocks; j++) {
            if (!blocks[j].allocated && 
                blocks[j].size >= processes[i].size &&
                blocks[j].size < min_size) {
                best_idx = j;
                min_size = blocks[j].size;
            }
        }
        
        if (best_idx != -1) {
            blocks[best_idx].allocated = 1;
            blocks[best_idx].process_id = processes[i].pid;
            processes[i].allocated = 1;
            processes[i].block_no = best_idx + 1;
        }
    }
}

void worstFit(struct block blocks[], int num_blocks, 
              struct process processes[], int num_processes) {
    
    for (int i = 0; i < num_processes; i++) {
        int worst_idx = -1;
        int max_size = -1;
        
        for (int j = 0; j < num_blocks; j++) {
            if (!blocks[j].allocated && 
                blocks[j].size >= processes[i].size &&
                blocks[j].size > max_size) {
                worst_idx = j;
                max_size = blocks[j].size;
            }
        }
        
        if (worst_idx != -1) {
            blocks[worst_idx].allocated = 1;
            blocks[worst_idx].process_id = processes[i].pid;
            processes[i].allocated = 1;
            processes[i].block_no = worst_idx + 1;
        }
    }
}

void displayResults(struct process processes[], int num_processes, 
                    struct block blocks[], char* algorithm) {
    printf("\n========================================\n");
    printf("%s Results\n", algorithm);
    printf("========================================\n");
    printf("Process\tSize\tBlock\tBlock Size\tFragmentation\n");
    printf("--------------------------------------------------------\n");
    
    int total_fragmentation = 0;
    int allocated_count = 0;
    
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%d\t", processes[i].pid, processes[i].size);
        if (processes[i].allocated) {
            int block_idx = processes[i].block_no - 1;
            int fragmentation = blocks[block_idx].size - processes[i].size;
            printf("%d\t%d\t\t%d\n", 
                   processes[i].block_no,
                   blocks[block_idx].size,
                   fragmentation);
            total_fragmentation += fragmentation;
            allocated_count++;
        } else {
            printf("NA\tNA\t\tNA\n");
        }
    }
    
    printf("--------------------------------------------------------\n");
    printf("Total Internal Fragmentation: %d\n", total_fragmentation);
    printf("Processes Allocated: %d/%d\n", allocated_count, num_processes);
    printf("========================================\n");
}

int main() {
    int num_blocks, num_processes;
    struct block blocks[10], original_blocks[10];
    struct process processes[10];
    
    printf("========================================\n");
    printf("Memory Allocation Techniques Simulator\n");
    printf("========================================\n");
    
    printf("\nEnter number of memory blocks: ");
    scanf("%d", &num_blocks);
    
    for (int i = 0; i < num_blocks; i++) {
        printf("\nEnter size of Block %d: ", i + 1);
        scanf("%d", &blocks[i].size);
        original_blocks[i].size = blocks[i].size;
        blocks[i].allocated = 0;
        blocks[i].process_id = -1;
    }
    
    printf("\nEnter number of processes: ");
    scanf("%d", &num_processes);
    
    for (int i = 0; i < num_processes; i++) {
        processes[i].pid = i + 1;
        printf("\nEnter size of Process %d: ", i + 1);
        scanf("%d", &processes[i].size);
        processes[i].allocated = 0;
        processes[i].block_no = -1;
    }
    
    // First Fit
    resetBlocks(blocks, original_blocks, num_blocks);
    resetProcesses(processes, num_processes);
    firstFit(blocks, num_blocks, processes, num_processes);
    displayResults(processes, num_processes, blocks, "First Fit");
    
    // Best Fit
    resetBlocks(blocks, original_blocks, num_blocks);
    resetProcesses(processes, num_processes);
    bestFit(blocks, num_blocks, processes, num_processes);
    displayResults(processes, num_processes, blocks, "Best Fit");
    
    // Worst Fit
    resetBlocks(blocks, original_blocks, num_blocks);
    resetProcesses(processes, num_processes);
    worstFit(blocks, num_blocks, processes, num_processes);
    displayResults(processes, num_processes, blocks, "Worst Fit");
    
    return 0;
}
