extern char title[250][70];
extern int year[250];
extern double rating[250];
extern int length[250];
extern char age[250][20];
extern char genre[250][30];
extern int position[250];

void read_movies(void); 
void write_movies(void);
int compare_rating(int, int);
int compare_length(int , int );
void sort_movies(int (* compare)(int, int));
void sort_movies_tie(int (* compare1)(int, int), int (* compare2)(int, int));
