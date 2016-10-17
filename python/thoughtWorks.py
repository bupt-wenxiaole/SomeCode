#thought_works homework
#author : Xiaole Wen
#Tel : 15810680829
#Email : xiaolewen_bupt@163.com

from datetime import datetime

#the standart is hardcode
weekday_fee_standard = [[9, 12, 30], [12, 18, 50],  
                        [18, 20, 80], [20, 22, 60]]
weekend_fee_standard = [[9, 12, 40], [12, 18, 50],
                        [12, 18, 50], [18, 22, 60]]


def calculate_pay_of_one_ground(start, end, is_weekday):
    assert(isinstance(is_weekday, bool))
    res = 0
    if(is_weekday):
        for i in range(0, len(weekday_fee_standard)):
            if start >= weekday_fee_standard[i][0] and start <= weekday_fee_standard[i][1]: #find the first range match
                for j in range(i, len(weekday_fee_standard)):
                    if(end <= weekday_fee_standard[j][1]):
                        res += (end - start) * weekday_fee_standard[j][2]
                        return res
                    else:
                        res += (weekday_fee_standard[j][1] - start) * weekday_fee_standard[j][2]
                        start = weekday_fee_standard[j][1]
    else:
        for i in range(0, len(weekend_fee_standard)):
            if start >= weekend_fee_standard[i][0] and start <= weekend_fee_standard[i][1]: #find the first range match
                for j in range(i, len(weekend_fee_standard)):
                    if(end <= weekend_fee_standard[j][1]):
                        res += (end - start) * weekend_fee_standard[j][2]
                        return res
                    else:
                        res += (weekend_fee_standard[j][1] - start) * weekend_fee_standard[j][2]
                        start = weekend_fee_standard[j][1]

def is_weekday(date):
    assert(isinstance(date, datetime))
    if(datetime.isoweekday(date) >= 1 and datetime.isoweekday(date) <= 5):
        return True
    else:
        return False

def input_entries():  #get the input line from stdin and put it in list
    list_of_input_line = []
    try:
        while True:
            line = raw_input()
            list_of_input_line.append(line.split())
    except EOFError:
        pass
    return list_of_input_line


def number_of_ground(M):  #M means the number of player
    T = M / 6
    X = M % 6
    if(T == 0 and X < 4):
        return 0
    elif(T == 0 and X >= 4):
        return 1
    elif(T == 1):
        return 2
    elif((T == 2 or T == 3) and (X < 4)):
        return T
    elif((T == 2 or T == 3) and (X >= 4)):
        return T + 1
    else:
        return T

def process_entries(list_of_input_line):
    print "[Summary]"
    print 
    total_income = 0
    total_payment = 0
    total_profit = 0
    for entry in list_of_input_line:
        date_object = datetime.strptime(entry[0], '%Y-%m-%d')
        list_of_hour_begin_end = entry[1].split("~")
        list_of_hour_begin_end = map(lambda x : int(x[:2]), list_of_hour_begin_end)
        number_of_groud_order = number_of_ground(int(entry[2]))
        if number_of_groud_order == 0: #cancel the order
            pay = 0
            income = 0
        else:
            income = int(entry[2]) * 30
            if(is_weekday(date_object)):
                pay = calculate_pay_of_one_ground(list_of_hour_begin_end[0], list_of_hour_begin_end[1], True) * \
                number_of_groud_order
            else:
                pay = calculate_pay_of_one_ground(list_of_hour_begin_end[0], list_of_hour_begin_end[1], False) * \
                number_of_groud_order
        profit = income - pay
        if profit > 0:
            str_profit = '+' + str(profit)
        else:
            str_profit = str(profit)
        print entry[0], entry[1], '+' + str(income), '-' + str(pay), str_profit
        total_income += income
        total_payment += pay
        total_profit += profit
    print ""
    print "Total Income:", total_income
    print "Total Payment:", total_payment
    print "Profit:", total_profit

if __name__ == "__main__":
    list_of_input = input_entries()
    process_entries(list_of_input)
    