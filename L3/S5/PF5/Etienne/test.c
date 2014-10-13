char* recup(int i){
  char * buffer = calloc(10,sizeof(char));
  char * result = calloc(10,sizeof(char));
  int j = 10;
  int c = 0;
  while(i!=0){
    buffer[c] = i%j;
    i = i/10;
    c++;
  }
  for(j=0;j++;j<c){
    result[j]=buffer[(c-1)-j];
  }
  return result;
}
