#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "library.h"

int main(){
  //testing insert_front
  srand(time(NULL));
  char s1[256], s2[256], s3[256], s4[256], a1[256], a2[256], a3[256], a4[256];
  strcpy(s1, "Shards of Light");
  strcpy(s2, "Fluquor");
  strcpy(s3, "Alive");
  strcpy(s4, "Biotonic");
  strcpy(a1, "Arn Andersson");
  strcpy(a2, "Onoken");
  strcpy(a3, "Philip Lober");
  strcpy(a4, "Ani");

  //strcpy(t1->name, s1);
  //strcpy(t1->artist, a1);
  printf("Beginning Testing Sequence\n");
  song_node * t1 = insert_front(0, s1, a1);
  print_list(t1);
  printf("Testing Insert_Front\n");
  t1 = insert_front(t1, s2, a2);
  print_list(t1);
  //testing insert
  printf("Testing Insert\n");
  t1 = insert(t1, s3, a3);
  print_list(t1);
  t1 = insert(t1, s4, a4);
  print_list(t1);
  printf("Testing findSong\n");
  song_node * searchResult = findSong(t1,s3);
  printf("\t[%s] by %s\n", (*searchResult).name, (*searchResult).artist);
  printf("Testing findArtist\n");
  searchResult = findArtist(t1, a4);
  printf("\t[%s] by %s\n", (*searchResult).name, (*searchResult).artist);
  printf("Testing randomNode\n");
  song_node * rndNode = randomNode(t1);
  printf("\t[%s] by %s\n", (*rndNode).name, (*rndNode).artist);
  //free(rndNode);
  print_list(t1);
  printf("Testing removeNode\n");
  print_list(t1);
  printf("Removing:[%s] by %s\n",s1,a1);
  t1 = removeSong(t1, s1, a1);
  print_list(t1);
  printf("Testing freeNodes\n");
  print_list(t1);
  t1 = freeNodes(t1);
  printf("Testing if t1 is null:[%d]\n", t1 == 0);
  
  //library testing begins:
  //extra songs for testing
  char s5[256], s6[256], s7[256], a5[256], a6[256], a7[256];
  strcpy(s5, "Grey");
  strcpy(s6, "A Bella!");
  strcpy(s7, "DRG");
  strcpy(a5, "Ed Carlsen");
  strcpy(a6, "M2U");
  strcpy(a7, "Ani");
  library * t2 = (library *)calloc(1,sizeof(library));

  //testing add
  printf("Testing addSong\n");
  addSong(t2, s5, a5);
  printf("Added song, now printing library:\n");
  printLibrary(t2);
  //adding the rest
  printf("Adding additional songs\n");
  addSong(t2, s1, a1);
  addSong(t2, s2, a2);
  addSong(t2, s3, a3);
  addSong(t2, s4, a4);
  addSong(t2, s6, a6);
  addSong(t2, s7, a7);
  printLibrary(t2);

  //testing other prints
  printf("Testing searchSong\n");
  printf("Searching for:[%s]\n",s1);
  searchResult = searchSong(t2, s1);
  printf("Printing out node: songName[%s], artistName[%s]\n", (*searchResult).name, (*searchResult).artist );
  printf("Testing searchArtist\n");
  printf("Searching for:[%s]\n",a3);
  searchResult = searchArtist(t2, a3);
  printf("Printing out node: songName[%s], artistName[%s]\n", (*searchResult).name, (*searchResult).artist );
  printf("Testing deleteSong\n");
  printf("Deleting:[%s] by %s\n",s1,a1);
  deleteSong(t2,s1,a1);
  printLetter(t2, tolower(a1[0]));
  printf("Testing printLetter\n");
  printLetter(t2, 'a');
  printLetter(t2, 'o');
  printLetter(t2, 'z');
  printf("Testing printArtist\n");
  printArtist(t2, a7);
  //printArtist(t2, "Ed Carlsen");
  //printArtist(t2, "Ani");
  //printArtist(t2, "AAAAAAAAAHGGGGGGGGGGGGGGG");
  printf("Testing shuffleList\n");
  shuffleList(t2);
  printf("Testing deleteLibrary\n");
  deleteLibrary(t2);
  //printf("If t2 == 0:[%d]\n", t2 == 0);
  printf("Printing out Library:\n");
  printLibrary(t2);
  printf("Printing complete. Confirm it is empty\n");
  return 0;
}
