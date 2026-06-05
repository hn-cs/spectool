/*@
requires \valid_read(&first) && \valid_read(&second);
ensures \result >= 0;
ensures \result == -1 <==> (first < 0 || first > 180 || second < 0 || second > 180 || first + second > 180);
ensures \result != -1 ==> \result == 180 - first - second;
*/
int last_angle(int first,int second){
    if(first < 0 || first > 180 || second < 0 || second > 180 || first + second > 180){
        return -1;
    }
    return 180 - first - second;
}
int main(){
    int first = 60;
    int second = 90;
    int result = last_angle(first,second);
    //@ assert result == 30;

    first = 100;
    second = 100;
    result = last_angle(first,second);
    //@ assert result == -1;
    return 0;
}