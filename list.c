#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[256];
  char artist[256];
  song_node *next;
} song_node;

song_node * insert_front( song_node *current, char *n, char *art){
  song_node * newNode = (song_node *)malloc( sizeof(song_node) );
  (*newNode).name = *n;
  (*newNode).artist = *art;
  (*newNode).next = current;
  return newNode;
}

song_node * insert( song_node *current, char *n, char *art){
  song_node * newNode = (song_nude *)malloc(sizeof(song_node) );
  (*newNode).name = *n;
  (*newNode).artist = *art;
  song_node * frs = current;
  while( strcmr( *current.artist, *newNode.artist ) <= 0 ){
    current = *current.next;
  }
  song_node * temp = *current.next;
  *current.next = newNode;
  *newNode.next = temp;
  return frs;
}

void print_list( song_node * head){
  printf("Begin: ");
  while(head != 0){
    printf("[%s] by %s;", *head.name, *head.artist);
    head = *head.next;
  }
  printf(":End\n");
}