
file_wordcnt(){
    
    
    word_num=$(wc -w $FILE)
    
    echo “$FILE 파일의 단어는 $word_num 개 입니다.”
}
read -p "Enter a file name: " FILE

file_wordcnt $FILE