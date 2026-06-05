/*@
requires second > 0 && second < 180;
requires first > 0 && first < 180;
requires first + second < 180;
ensures \result > 0;
ensures \result == 180 - first - second;
assigns \nothing;
*/
int last_angle(int first, int second){
    return 180 - first - second ;
}
int main(){
    int first = 45;
    int second = 45;
    int result = last_angle(first, second);
    //@ assert result == 90;
}