void triFusion(int * tab, int n ){
  int pipe1[2];
  int pipe2[2];
  if(n<2){
    write(stdout,tab,n);
  }
  else{
    pipeP[2]
    pipe(pipe[0]);
    pipe(pipe[1]);
    pid_t p1 = fork();
    if(p1 == 0){
      dup2(pipe1[1],stdout);
      triFusion(tab,n/2);
    }
    else{
      int p2 = fork();
      if(p2 == 0){
        dup2(pipe[1],stdout);
        triFusion(tab+n/2,n/2);
      }
      else{
        int tmp[2];
        int pi = 0;
        read(pipe1[0],&tmp[0],BUFFSIZE);
        read(pipe2[1],&tmp[1],BUFFSIZE);
        if(tmp[0] > tmp[1]) {
          pi = 1;
          write(stdout,&tmp[1],1);
        }
        else{
          pi=0
          write(stdout,&tmp[0],1)
        }
        while(read(pipeP[pi][0],&tmp[pi],BUFFSIZE) != -1){
          //read(pipe[pi],&tmp[pi],BUFFSIZE);

          if(tmp[0] > tmp[1]) {
            pi = 1;
            write(stdout,&tmp[1],1);
          }
          else{
            pi=0
            write(stdout,&tmp[0],1)
          }
        }
      }
    }
  }
}
