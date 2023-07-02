read -p "Enter file name: " file
read -p "Enter the start and end: " start end

sed -n $start,$end\p $file

echo -e "\n"
read -p "Enter File Name: " file
read -p "Enter Word: " word

echo -e "\nFile after removing word:\n"
echo "`cat $file | grep -v $word`"

echo -e "\n\nThe files are:\n`ls`"