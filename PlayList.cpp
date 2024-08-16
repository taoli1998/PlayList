// Author: Tao Li
// Date: May 30, 2022

#include "PlayList.h"
#include <iostream>
using namespace std;

//PlayList method implementations go here
//default constructor
PlayList::PlayList(){
    head = NULL;
}

//copy constructor
PlayList::PlayList(const PlayList& pl){
    if (pl.head == NULL){
        cout<<"The list is empty!"<<endl;
    }
    else{
        head = new PlayListNode(pl.head->song);

        PlayListNode *NewNode = head;
        PlayListNode *OldNode = pl.head->next;

        while(OldNode != NULL){
            NewNode->next = new PlayListNode(OldNode->song);
			NewNode = NewNode->next;
			OldNode = OldNode->next;
        }

        NewNode->next = NULL;
    }
}

//destructor
PlayList::~PlayList(){
    PlayListNode *curr = head;
    while (curr != NULL){
        head = head->next;
        delete curr;
        curr = head;
    }
    head = NULL;
    

};

//insert
void PlayList::insert(Song sng, unsigned int pos){
    PlayListNode *temp = head;
    PlayListNode *NewNode = new PlayListNode(sng);

    unsigned int i=0;
    if (pos ==0){ 
        NewNode->next = temp;
        head = NewNode;
    }
    else{
        while(temp->next != NULL&&i<pos-1){
            i++;
            temp = temp->next;
        }
        PlayListNode *t1 = temp->next;
        temp->next= NewNode;
        NewNode->next = t1;
    }
 }

//remove
Song PlayList::remove(unsigned int pos){
    PlayListNode *temp = head;
    if (head ==NULL){
        cout<<"The list is empty!"<<endl<<endl;
    }
    if (pos ==0){
        head = head->next;
        Song s1 = temp->song;
        cout<<"You removed "<<temp->song.getName()<<" from the play list."<<endl<<endl;
        delete temp;
        return s1;
    }
    else{
        for(unsigned int i=0;i<pos-1;i++){
            temp = temp->next;
        }
        PlayListNode *temp1 = temp->next;
        Song s2 = temp->next->song;
        temp->next = temp->next->next;
        cout<<"you removed "<<temp1->song.getName()<<" from the play list."<<endl<<endl;
        delete temp1;
        return s2;
    }
}

//swap
void PlayList::swap(unsigned int pos1, unsigned int pos2){
    
    if(pos1 == pos2){
        cout<<"pos1 = pos2, nothing changes!"<<endl<<endl;
        return;
    }
    if(pos1>pos2){
        pos1 = pos1+pos2;
        pos2 = pos1-pos2;
        pos1 = pos1-pos2;
    }
    PlayListNode *PrePos1 = NULL;
    PlayListNode *CurrPos1 = head;
    unsigned int i=0;
    while (CurrPos1->next != NULL && i<pos1-1){
                i++;
                PrePos1 = CurrPos1;
                CurrPos1 = CurrPos1->next;
    }
    PlayListNode *PrePos2 = NULL;
    PlayListNode *CurrPos2 = head;
    unsigned int j=0;
    while (CurrPos2->next != NULL && j<pos2-1){
                j++;
                PrePos2 = CurrPos2;
                CurrPos2 = CurrPos2->next;
    }
    if (PrePos1!=NULL){
        PrePos1->next = CurrPos2;
    }
    else{
        head = CurrPos2;
    }
    if (PrePos2!=NULL){
        PrePos2->next = CurrPos1;
    }
    else{
        head = CurrPos1;
    }
    PlayListNode *temp = CurrPos2->next;
    CurrPos2->next = CurrPos1->next;
    CurrPos1->next = temp;
    cout<<"You swapped the songs at positions "<<pos1<<" and "<<pos2<<"."<<endl<<endl;
    
}

//get
Song PlayList::get(unsigned int pos) const{
    PlayListNode *temp = head;
    
    unsigned int i=0;
    if (head == NULL){ 
        cout<<"empty list"<<endl;
        Song s = head->song;
        return s;
    }
    else{
        while(temp->next != NULL&&i<pos){
            
            i++;
            temp = temp->next;
        }
        return temp->song;
    }
    
}

//overloaded assignment operator
PlayList& PlayList::operator=(const PlayList & pl){
    
    PlayList *list = new PlayList();
    if (pl.head == NULL){
        cout<<"The list is empty!"<<endl;
    }
    else{
        head = new PlayListNode(pl.head->song);

        PlayListNode *NewNode = head;
        PlayListNode *OldNode = pl.head->next;

        while(OldNode != NULL){
            NewNode->next = new PlayListNode(OldNode->song);
			NewNode = NewNode->next;
			OldNode = OldNode->next;
        }

        NewNode->next = NULL;
    }
    return *list;
};

//size
unsigned int PlayList::size() const{
    PlayListNode *temp = head;
    unsigned int count = 0;
    if (head == NULL){
        return count;
    }
    else{
        while(temp !=NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }

}

//print
void PlayList::print(const PlayList &pl){
    PlayListNode *temp = head;
    if(head == NULL){
        cout<<"The list is empty!"<<endl;
    }
    else{
        cout<<"Song in the list: "<<endl;
        for(unsigned int i=0; i<pl.size(); i++){
            cout<<i+1<<" "<<temp->song.getName()<<" ("<<temp->song.getArtist()<<") "<<temp->song.getLength()<<"s."<<endl;
            temp = temp->next;
        }
        if (pl.size()==1){
            cout<<"There is only 1 song in the play list."<<endl<<endl;
        }else{
            cout<<"There are "<<pl.size()<<" songs in the play list."<<endl<<endl;
        }
        
    }
}