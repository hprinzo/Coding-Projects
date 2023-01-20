#pragma once
#ifndef TICKET_H_

#define TICKET_H_
// struct Message
struct Message
{
    char account_Type;
    char full_name[31];
    char message_Details[151];
};
//struct Ticket
struct Ticket
{
    int ticket_Number;
    int account_Number;
    int ticket_Status;
    char sub[31];
    int number_Of_Messages;
    struct Message messages[20];
};

#endif