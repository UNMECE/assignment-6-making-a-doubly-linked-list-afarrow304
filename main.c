#include"coordinate.h"
#include <stdio.h>
#include <cstdlib>
#include <random>

//add_coordinate: add's a coordinate to the end of the linked list
void add_coordinate(Coordinate *list_end, float x, float y){
//	Coordinate *new_coord=(Coordinate *)malloc(sizeof(Coordinate));
	Coordinate *new_coord = new Coordinate;
	new_coordx = x;
	new_coord-> y = y;
	new_coord->coord_id=coord_id;
	new_coord->next=NULL;
	new_coord->previous=list_end;
	list_end->next=new_coord;
}

//forward_display: displays all coordinates from beginning to end
void forward_display(Coordinate *list_beginning){
	Coordinate *current = list_beginning;
	while(current!=NULL)
	{
		printf("coord_id: %d, X: %.2f, Y: %.2f\n", current->coord_id,
		current->x, current->y);
		current = current->next;
	}

}

//backwards_display: displays all coordinates from end to beginning
void backward_display(Coordinate *list_end){
	Coordinate *current = list_end;
	while(current!=NULL)
	{
		printf("coord_id: %d, X: %.2f, Y: %.2f\n", current->coord_id, 
		current->x, current->y);
		current = current->previous;

}

//delete_coordinate: removes a coordinate from the linked list
//(free memory!)
void delete_coordinate(Coordinate *list_beginning, int coord_id_to_delete){
	Coordinate *temp = list_beginning;
	while(temp!=NULL)
	{
		if(temp->coord_id==coord_id_to_delete)
		{
			if(temp->previous!=NULL){
				temp->previous->next = temp->next;
			}else{
				list_beginning=temp->next;
			}
			if(temp->next!=NULL){
				temp->next->previous=temp->previous;
			}
			delete temp;
		}
		temp= temp->next;
	}
}

//return the length of the list
int list_length(Coordinate *list_beginning){
	int lengthCount=0;
	Coordinate *current = list_beginning;
	while(current!=NULL)
	{
		lengthCount++;
		current = current->next;
	}
	return lengthCount;
}

//find the coordinate that is closest to the given x, y 
//and output the distance between the 2
void closest_to(Coordinate *list_beginning, float x, float y){
	Coordinate *current = list_beginning;
	Coordinate *closest = NULL;
	float minDistBetween=sqrt(pow(current->x - x, 2)+ pow(current->y - y, 2));
	while(current!=NULL){
		float distance=sqrt(pow(current->x - x, 2) + pow(current->y - y, 2));
		if(distance<minDistBetween){
			minDistBetween=distance;
			closest = current;
		}
		current = current->next;
	}
	printf("the coordinate that is closest to (%.2f,%.2f) is Coordinate id: %d, ",x,y, closest_>coord_id)
	Printf("the distance between the two is %.2f\n",minDistBetween);
}

//Use random numbers to fill the x and y coordinates,
//make the number of coordinates arbitrary and taken from the command line
int main(int argc, char *argv[]){
	int numCoordinates= std::atoi(argv[1]);
	Coordinate *list_beginning=NULL;
	Coordinate *list_end=NULL;
	int max=10, min =0;
	for(i=0;i<numCoordinates;i++){
		float rand_Y_coordinate=std::rand()%(max-min);
		float rand_X_coordinate=std::rand()%(max-min);
		add_coordinate(list_end, rand_X_coordinate, rand_Y_coordinate);
	}
//use each function to add coordinates,display the list,
//delete a coordinate, and find the closest to.
//You can just supply values to the function of delete coordinate
//and closest to functions.
forward_display(list_beginning);
backward_display(list_end);
delete_coordinate(list_beginning,coordId);
closest_to(list_beginning,1,5);
return 0;
}
