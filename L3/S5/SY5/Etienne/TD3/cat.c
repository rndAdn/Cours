void cat(int des){
  int lus;
  char buf[BUFSIZE];
  while(lus = read(des,buf,bufsize)){
    write(STDOUT_FILENO,buf,lus),
  }
}
