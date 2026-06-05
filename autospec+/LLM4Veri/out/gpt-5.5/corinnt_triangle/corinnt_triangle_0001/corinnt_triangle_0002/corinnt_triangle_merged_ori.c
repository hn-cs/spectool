/*@
requires -2147483648 <= 180 - first - second <= 2147483647;
requires -2147483467 <= first;
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
    // @ assert result == 90;
}