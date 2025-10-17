import sys

def is_leap(year):
    return (year % 4) == 0 and ( (year % 100) != 0 or (year % 400) == 0 )

def wrong(input):
    print('\nWrong input ({0}). \nTry again / press q+↵ to terminate'.format(input))

#variable to be used later
VALID = False
DATE = day = month = year = 0


#To remove erroneous inputs
while (not VALID):
    #Taking the user input
    DATE = input("Enter the date (dd-mm-yyyy) : ")

    if DATE in ['q', 'Q']:
        sys.exit()

    #Proccess the input to get values of day month and year
    date = DATE.split("-")

    if len(date) != 3:
        wrong("wrong format only use '-' in dd-mm-yyyy")
        print("Remove string / special characters other than '-' (if present).")
        continue

    try:
        day = int(date[0])
        month = int(date[1])
        year = int(date[-1])
    except ValueError:
        print("\nPlease remove string / special characters other than '-'.")
        continue

    if year not in list(range(1900,2051)):
        wrong('please input year between 1900-2050')
        continue

    elif month in {2}:
        if day>0 and day<=29:
            if day == 29 and is_leap(year) or day != 29:
                break
            else:
                wrong('not a leap year')
        else:
            wrong('day is not valid')

    elif month in {1, 3, 5, 7, 8, 10, 12}:
        if day>0 and day<=31:
            break
        else:
            wrong('day is not valid')

    elif month in {4, 6, 9, 11}:
        if day>0 and day<=30:
            break
        else:
            wrong('day is not valid')

    else:
        wrong('month is not valid')



century_digits = int(year/100)

year_digits = int(year%(century_digits*10))

value = year_digits + year_digits//4

if century_digits == 18:
    value += 2

if year == 1900 and month in [1, 2]:
    value +=1

elif century_digits == 20:
    value += 6


#January
if month == 1 and year % 4 != 0: 
    value += 1

elif month == 2 and year % 4 == 0:
    value += 3
elif month == 2:
    value += 4

elif month in [3, 11]:
    value += 4

elif month == 5:
    value += 2

elif month == 6:
    value += 5

elif month == 8:
    value += 3

elif month == 10:
    value += 1

value = (value + day) % 7

weekday_dictionary = {
        0: 'Saturday', 
        1: 'Sunday',
        2: 'Monday',
        3: 'Tuesday', 
        4: 'Wednesday', 
        5: 'Thursday', 
        6: 'Friday', 
    }


#Output
print("The day on", DATE, " is", weekday_dictionary[value])