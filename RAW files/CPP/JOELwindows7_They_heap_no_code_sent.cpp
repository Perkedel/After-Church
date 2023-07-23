#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

struct Data {
	int score;
	char nim[11];
	
	
}heap[100000];

int lastNodeIdx = 1; //last index

void swap(int idx1, idx 2){
	struct Data temp = heap[idx1];
	heap[idx1] = heap[idx2];
	head[idx2] = temp;
}

void insert(struct Data newData) {
	int newNodeIdx = lastNodeIdx;
	lastNodeIdx++;
	heap[newNodeIdx] = newData;
	
	
	//upheap
	int compareIdx = newNodeIdx;
	while(newNodeIdx != 1){
		int parentIdx = newNodeIdx /2;
		if(heap[parentIdx] > heap[newNodeIdx].score){
			swap(compareIdx, parentIdx);
			
		} else {
			break;
		}
		compareIdx = parentIdx;
	}
	
	lastNodeIdx = newNodeIdx;
}

void altInsert(struct Data newData){
	lastNodeIdx++;
	heap[lastNodeIdx] = newData;
	
	int curr = lastNodeIdx;
	while(curr != 1 && heap[curr].score > heap[curr/2].score){ //upheap
		swap(curr, (curr/2));
		curr = curr/2;
	}
}

void downheap(int idx){
	int curr = idx;
	int currValue = heap[Idx].score;
	
	if(idx*2 <= lastNodeIdx && heap[idx*2] > currValue){
		curr = idx*2;
		currValue = heap[idx*2].score;
	}else if(idx*2+1 <= lastNodeIdx && heap[idx*2+1] > currValue){
		curr = idx*2+1;
		currValue = heap[idx*2+1].score;
	}
	
	if(curr == idx) return;
	
	swap(curr, idx);
	downheap(curr);
}

void pop(int idx){
	if(lastNodeIdx = 0){ //no data
		
	} else if(lastNodeIdx == 1){ //left 1
		lastNodeIdx--;
	} else { //many data
		heap[1] = heap[lastNodeIdx];
		lastNodeIdx--;
		downheap(1);
	}
}

