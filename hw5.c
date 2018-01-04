#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LENGTH 1000

struct clip *build_a_lst();
struct clip *append();
int find_length();
void print_a_lst();
void split_line();

struct clip {
  int views;
  char *user;
  char *id;
  char *title;
  char *time;
  struct clip *next;
} *head;

int main(int argc, char **argv) {
  int n;
  head = build_a_lst(*(argv+1));
  n = find_length(head);
  printf("%d clips\n", n);
  print_a_lst(head);   /* prints the table */
  return 0;
}

struct clip *build_a_lst(char *fn) {
  FILE *fp;
  struct clip *hp;
  char *fields[5];
  char line[LINE_LENGTH];
  int cnt=0;
  hp=NULL;

  // open fn
  // while no more lines
  // read a line
  // split the line into four substrings/int and store them in a struct
  // append - add the struct at the end of the list
  // return the head pointer holding the list

  fp = fopen(fn, "r");

  while (fgets(line, LINE_LENGTH, fp) != NULL) {
    split_line(fields, line);
    hp = append(hp, fields);
  }

  fclose(fp);

  return hp;
}

int find_length(struct clip *hp) {
    int i = 0;
    struct clip* cp = hp;
    
    while (cp != NULL) 
    {
        i++;
        cp = cp->next;
    }
    
    return i;
}

void split_line(char **fields, char *line) {
  int i=0;
  char *token, *delim;
  delim = ",\n";

  /* 
     call strtok(line, delim);
     repeat until strtok returns NULL using strtok(NULL, delim);
 */

  token = strtok(line,delim);
  // create space for token and add to fields
  fields[i]=malloc(sizeof(token));
  strcpy(fields[i], token);
  i++;

  while (token != NULL) {
    token = strtok(NULL, delim);
    if (token != NULL) {
      fields[i]=malloc(sizeof(token));
      strcpy(fields[i], token);
      i++;
    }
  }
}

/* set four values into a clip, insert a clip at the of the list */
struct clip *append(struct clip *hp,char **five) {
  struct clip *cp,*tp;

  /* 
     malloc tp
     set views using atoi(*five)
     malloc for four strings.
     strcpy four strings to tp
     insert tp at the end of the list pointed by hp
     use cp to traverse the list
 */

  cp = hp; tp = NULL;

  
  
  tp = malloc(sizeof(struct clip));
  tp->next = NULL;

  tp->user = malloc(sizeof(five[0]));
  strcpy(tp->user, five[0]);


  tp->views = atoi(five[1]);


  tp->id = malloc(sizeof(five[2]));
  strcpy(tp->id, five[2]);


  tp->title = malloc(sizeof(five[3]));
  strcpy(tp->title, five[3]);

  tp->time = malloc(sizeof(five[4]));
  strcpy(tp->time, five[4]);

  if (cp == NULL) {
    hp = tp;
  }
  else {
    
    while (cp->next != NULL) 
      cp = cp->next;

    cp->next = tp;
  }

  
  return hp;
}

void print_a_lst(struct clip *cp) {
  /* 
     use a while loop and the statement below to print the list
     printf("%d,%s,%s,%s,%s\n",cp->views,cp->user,cp->id,cp->title,cp->time);
  */

  cp = head;
  while (cp != NULL) {
    printf("%d,%s,%s,%s,%s\n",cp->views,cp->user,cp->id,cp->title,cp->time);
    cp= cp->next;
  }
}

/* end */
