var numUniqueEmails = function(emails) {
    var uniqueEmails = new Set(); // Set to store unique email addresses

    for (var i = 0; i < emails.length; i++) {
        var email = emails[i];
        var parts = email.split('@'); // Split email into local and domain parts

        var local = parts[0];
        var domain = parts[1];

        // Remove dots from local part
        local = local.replace(/\./g, '');

        // Remove everything after '+' from local part
        if (local.includes('+')) {
            local = local.substring(0, local.indexOf('+'));
        }

        var newEmail = local + '@' + domain;
        uniqueEmails.add(newEmail);
    }

    return uniqueEmails.size;
};

var emails = ["test.email+alex@leetcode.com", "test.e.mail+bob.cathy@leetcode.com", "testemail+david@lee.tcode.com"];
console.log(numUniqueEmails(emails));