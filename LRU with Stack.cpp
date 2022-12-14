
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <climits>
#include <iostream>
#include <vector>

struct Node {
   int data;
   struct Node *prev;
   struct Node *next;
};

struct Node* head = NULL;
struct Node* curr = NULL;
struct Node* last = NULL;
struct Node* temp = NULL;
void insert(int newdata) {
   struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
   newnode->data  = newdata;
   newnode->prev = NULL;
   newnode->next = head;
   if(head !=  NULL)
      head->prev = newnode ;
   head = newnode;
}

int lru_stack(int *v, int no_of_frames, int len_req){


    int counter=0;
    int faults=0;

    for(int i=0;i<len_req;i++){
       if(counter==0){
            insert(v[i]);
            counter++;
            last=head;
        }else {
            curr=head;
            int flag=0;
            int flag2=0;
            for(int k=0;k<no_of_frames;k++){
                if(flag==0 && flag2==0){
                    if(curr->data == v[i]){
                        flag=1;
                        if(curr->next==NULL && curr->prev!=NULL){
                        temp=curr->prev;
                        temp->next=NULL;
                        last=temp;
                        free(curr);
                        insert(v[i]);
                        }else if(curr->next==NULL && curr->prev==NULL){
                            //do nothing
                        }else if(curr->next!=NULL && curr->prev==NULL){
                            //do nothing
                        }else{
                            curr->prev->next = curr->next;
                            curr->next->prev = curr->prev;
                            free(curr);
                            insert(v[i]);
                        }
                    }else{
                    if(curr->next!=NULL){
                    curr=curr->next;
                    }else{
                    flag2=1;
                    }
                }
                }
            }
            if((flag==0) && (counter==no_of_frames)){
            last=last->prev;
            last->next=NULL;
            insert(v[i]);
            faults++;
            }else if((flag==0) && (counter!=no_of_frames)){
            insert(v[i]);
            counter++;
            }
        }
    }
    return faults;
}

 /*int main(){
     int v[12];
 	int frames=3;
     v[0]=1;
     v[1]=2;
     v[2]=3;
     v[3]=4;
     v[4]=5;
     v[5]=6;
     v[6]=7;
     v[7]=5;
     v[8]=3;
     v[9]=2;
     v[10]=5;
     v[11]=2;
 	int Faults = lru_stack(v,frames,12);
     std::cout<<Faults<<std::endl;
     return 0;
}*/
int main(int argc, char const *argv[])
{
	std::cout << "===LRU Page Replacement Algorithm Implementation===" << std::endl;
	std::cout << "Enter the length of request string : ";
	int len_req;
	std::cin >> len_req;

	int no_of_frames;
	std::cout << "Enter the number of frames to be used : ";
	std::cin >> no_of_frames;
	std::cout << "Enter the request string (Each entry followed by enter) : " << std::endl;
	int elem;
	std::vector<int> req_vec;
	int req_arr[len_req];
	for (int i = 0; i < len_req; ++i){

		std::cin >> elem;
		req_arr[i] = elem;
		req_vec.push_back(elem);

	}
	int faults;

			faults = lru_stack(req_arr, no_of_frames, len_req);


	std::cout << "Number of Page Faults generated : " << faults << std::endl;

	return 0;
}
