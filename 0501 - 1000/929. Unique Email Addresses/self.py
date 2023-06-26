def numUniqueEmails(emails):
    
        new_list = []
        
        for email in emails:
            temp = email.split('@')
            if '+' in temp[0]:
                temp[0] = temp[0].split('+')[0]
            if '.' in temp[0]:
                temp[0] = temp[0].replace(".", "")
                
            email = temp[0] + '@' + temp[1]
            new_list.append(email)
            
        return len(set(new_list))
        
emails = ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]

print(numUniqueEmails(emails))