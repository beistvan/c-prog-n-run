int fizzbuzz(int n){
    
    if (n <= 0) printf("no"); 
    else if( !(n % 3) && !(n % 5)) printf("fizzbuzz"); 
    else if(!(n % 3)) printf("fizz"); 
    else if(!(n % 5)) printf("buzz"); 
    
    return 0;
}
