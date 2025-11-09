
file_wordcnt(){
    files=$(ls *.txt)

    for f in $files; do
        word_num=$(wc -w < $f)
        echo "$f 파일의 단어는 $word_num 개 입니다."
    done
}

file_wordcnt