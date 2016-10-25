awk 'BEGIN{total=0}{total=total+$2}END{print total}' a.txt
