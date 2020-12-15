#!/bin/bash
#Justin Willis
#Code to get User to send them a temporary password and then force change

MY_MAIL="justin.willis@mymail.champlain.edu"

if [[ $EUID -ne 0 ]]; then
echo "This must be executed as user root."
exit 1
fi
group="CSI230" 
egrep -i $group /etc/group > /dev/null
if [ ! $? -eq 0 ]; then
groupadd $group
fi
 
file=$1
read -s -p "Please type in your password" input
for email in $(cat $file) 
do

UserName=$(echo $email | cut -d @ -f 1)
Passwdtmp=$(date +%s | sha256sum | base64 | head -c 12)
if [ id $UserName > /dev/null 2>&1 ]; then
echo $UserName:$Passwdtmp | chpasswd
echo "The user has changed their password!"
else
useradd -m $UserName
echo $UserName:$Passwdtmp | chpasswd

fi
passwd --expire $UserName
usermod -a -G $group $UserName
email_body="Hello $email, this is your temporary password: $Passwdtmp (Please change your password after you login)"
email_subject="Temporary Password"
email_to=$email
 
echo -e "${email_body}" | s-nail -S smtp-use-starttls -S ssl-verify=ignore -S smtp-auth=login -S smtp=smtp.gmail.com:587 -S from="${MY_MAIL}(Justin Willis)" -S smtp-auth-user=$MY_MAIL -S smtp-auth-password=$input -s "${email_subject}" -S ssl-verify=ignore "${email}"

done

 

