import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from datetime import date
import time
#                       Sales Analysis Sales Graph
def Sales_Graph():
        ans='Y'
        while ans=='Y' or ans=='y':
                a=pd.read_csv("Transaction.csv",index_col=0)
                x=a.Item_Name
                h=a.Qty
                print(h)
                plt.bar(x,h,label="Total Sales")
                plt.xlabel("Item_Name")
                plt.ylabel("Quantity")
                plt.xticks(x,rotation=90)
                plt.legend()
                plt.show()
                ans=input("DO you want to continue,Y or N:")
 
#                       Sales Analysis Monthwise Sales Graph
def Monthwise_Graph():
        ans='y'
        while ans=='y' or ans=='Y':
                bill=pd.read_csv("Transaction.csv",index_col=0)
                bill['Bill_Date']=pd.to_datetime(bill['Bill_Date'],dayfirst=True,format='mixed')
                newdf=pd.DataFrame(bill.groupby(bill['Bill_Date'].dt.month_name(locale="English"))['Total_Price'].sum(),columns=['Total_Price'])
                print(newdf)
                plt.bar(newdf.index,newdf.Total_Price)
                plt.xlabel('Month Name')
                plt.ylabel('Amount')
                plt.title('Monthwise Sale Comparision ')
                plt.show()
                ans=input("DO you want to continue,Y or N:")
                
#                        sales analisis year wise sales graph
def Yearwise_Graph():
        ans='y'
        while ans=='y' or ans=='Y':
                bill=pd.read_csv("Transaction.csv",index_col=0)
                bill['Bill_Date']=pd.to_datetime(bill['Bill_Date'],dayfirst=False,format='mixed')
                
                newdf=pd.DataFrame(bill.groupby(bill['Bill_Date'].dt.year)['Total_Price'].sum(),columns=['Total_Price'])
                print(newdf)
                plt.bar(newdf.index,newdf.Total_Price)
                plt.xticks(newdf.index,rotation=45)
                plt.xlabel('Year')
                plt.ylabel('Amount')
                plt.title('Yearwise Sale Comparision ')
                plt.show()
                ans=input("DO you want to continue,Y or N:")
                

#                       Bill Add Bill
def Add_Bill():
    v="Y"
    while v=='Y' or v=='y':
    
        trans = pd.read_csv("Transaction.csv")
        cus = pd.read_csv("Customer.csv", index_col=0)
        it = pd.read_csv("Item.csv", index_col=0)
        pd.set_option("display.max_rows", None)
        pd.set_option("display.max_columns", None)
        pd.set_option("display.max_colwidth", None)
        a = trans["Bill_No"].max() + 1 if not trans.empty else 1
        b = date.today()
        print(cus)
        c = int(input("Enter Customer_Id: "))
        if c in cus.index:
            d = cus.at[c, 'Cust_Name']
            print("Customer_Name:", d)
            f = cus.at[c, 'Cust_Address']
            print("Customer_Address:", f)
        else:
            print("Wrong Customer_Id")
            print("Try Again")
            continue
        bill_items = []
        while True:
            print(it)
            g = int(input("Enter Item Code: "))
            if g in it.index:
                h = it.at[g, 'Item_Name']
                print("Item_Name:", h)
                j = it.at[g, 'Price']
                print("Item_Price:", j)
            else:
                print("Wrong Item_Code")
                print()
                print("Try Again")
                continue
            i = int(input("Enter Quantity: "))
            if i <= 0:
                print("Quantity should be greater than 0")
                continue
            if i > it.at[g, "Stock"]:
                print("Insufficient Stock")
                print()
                print("Try Again")
                continue
            price = j
            print("Total Price:", price * i)
            n = j * i
            bill_items.append((h, i, j, n))
            ans = input("Do you want to buy more items (Y or N): ")
            if ans.lower() != "y":
                break
        if not bill_items:
            print("No items added to the bill.")
            continue
        print("Generating Bill...")
        print('-x' * 32)
        print('=' * 64)
        print("\t\tWelcome To NavJeevan Superstore")
        print('_' * 64)
        print('Bill_no : ', a, "\t", 'Bill Date : ', b, "\t", 'Name : ', d)

        print('_' * 64)
        print(f'{"Item_Name":<15}{"Item_Price":<15}{"Qty":<10}{"Total_Price":<15}')
        print('_' * 64)

        total_bill_amount = 0
        
        for item in bill_items:
            print(f'{item[0]:<15}{item[2]:<15}{item[1]:<10}{item[3]:<15}')
            total_bill_amount += item[3]
        
        print('_' * 64)
        print(f'{"Total Bill Amount:":<40}{total_bill_amount:<10}')
        print('_'*64)
        print('\t\tThank You Visit Again!!')
        print('=' * 64)
        print('-x' * 32)
        for item in bill_items:
            trans.loc[len(trans)] = [a, b, d, f, item[0], item[1], item[2], item[3]]
        for item in bill_items:
            it.loc[it.index == g, 'Stock'] -= item[1]
        it.to_csv("Item.csv")
        trans.to_csv("Transaction.csv", index=False)

        v = input("Do you want to add more bills (Y or N): ")
        
    Submenu3()


#                         Bill Delete Bill Details
def Delete_Bill():
        x=pd.read_csv("Transaction.csv",index_col='Bill_No')
        pd.set_option("display.max_rows",None)
        pd.set_option("display.max_columns",None)
        pd.set_option("display.max_colwidth",None)
        v="Y"
        while v=='Y' or v=='y':
                print(x)
                i=int(input("Enter Bill_Id To Be Deleted:"))
                if i in x.index:
                        x=x.drop([i],axis=0)
                        x.to_csv("Transaction.csv")
                        print(x)
                        print("Record deleted successfully")
                        v=input("Do you want to delete more records,Y or N:")
                else:
                        print("Wrong Bill_No")
                        print()
                        print("Try Again")
                        break                 


#                        Customer Details Add Cust Details
def Add_Customer():
        ans="Y"
        while ans=='Y' or ans=='y':
                 x=pd.read_csv("Customer.csv")
                 pd.set_option("display.max_rows",None)
                 pd.set_option("display.max_columns",None)
                 pd.set_option("display.max_colwidth",None)
                 a=(x.Cust_ID).max()+1
                 b=input("Enter Customer Name : ")
                 c=input("Enter Contact No : ")
                 if len(c)==10:
                         d=input("Enter Customer Address : ")
                         x.loc[len(x.Cust_ID),:]=[a,b,c,d]
                         x.to_csv("Customer.csv",index=False)
                         print(x)
                         print("Record Added Successfully")
                 else :
                         print("Number not valid!!!")
                 ans=input("Do you want to add more record,Y or N:")
#                         Customer Details Delete Cust Details
def Delete_customer():
        x=pd.read_csv("Customer.csv",index_col=0)

        v="Y"
        while v=='Y' or v=='y':
                print(x)
                i=int(input("Enter Cust_ID To Be Deleted:"))
                if i in x.index:
                        x=x.drop([i],axis=0)
                        x.to_csv("Customer.csv")
                        print(x)
                        print("Record deleted successfully")
                        v=input("Do you want to delete more records,Y or N:")
                else:
                        print("Wrong Cust_ID")
                        print()
                        print("Try Again")
                        break

#                                 cust menu update cust
def Update_Customer():
        cust=pd.read_csv("Customer.csv",index_col=0)
        l="Y"
        while l=='Y' or l=='y':
                print(cust)
                Cid=int(input("Enter Cust_Code to be Updated:"))
                if Cid in cust.index:
                        print("Select Column To Be Updated")
                        print(cust.columns)
                        Ccl=input("Enter Column Name to be updated:")
                        val=input("Enter new value:")
                        cust.loc[Cid,Ccl]=val
                        cust.to_csv("Customer.csv")
                        print(cust)
                        print("Record Updated Successfully")
                        l=input("Do you want to update more records,Y or N:")
                else:
                        print("Wrong Cust_Id")
                        print()
                        print("Try Again")
                        break        


#                               cust menu cust list
def Cust_List():
        f=pd.read_csv("Customer.csv")
        print(f)
        Submenu1()
#                               Item menu Add Item
def Add_Items():
        x=pd.read_csv("Item.csv")
        a="Y"
        while a=='Y' or a=='y':
                a=(x.Item_Code).max()+1
                b=input("Enter Brand Name : ")
                c=input("Enter Item Name : ")
                d=float(input("Enter Stock : "))
                e=float(input("Enter Price : "))
                x.loc[len(x.Item_Code),:]=[a,b,c,d,e]
                x.to_csv("Item.csv",index=False)
                print(x)
                print("Record added successfully")
                a=input("Do you want to add more record,Y or N:-")
#                               Item menu Delete Item
def Delete_Item():
        ans="Y"
        while ans=='Y' or ans=='y':
                d=pd.read_csv("Item.csv",index_col=0)
                print(d)
                index=int(input('Enter Item_Code'))
                if index in d.index:
                        d=d.drop([index],axis=0)
                        d.to_csv("Item.csv")
                        print("Record added successfully")
                        print(d)
                        ans=input("Do you want to delete more records,Y or N:")
                else:
                        print("Wrong Item_Code")
                        print()
                        print("Try Again")
                        break
#                       item menu update item
def Update_Item():
        s="Y"
        while s=='Y' or s=='y':
                df=pd.read_csv("Item.csv")
                print(df)
                id=int(input("Enter Item Code to be update"))
                if id in df['Item_Code'].values:
                        print("Select Column to be updated")
                        print(df.columns)
                        cl=input("Enter column name to update:")
                        val=input("Enter new value")
                        df.loc[df['Item_Code']==id,cl]=val
                        df.to_csv("Item.csv",index=False)
                        print(df)
                        print("Record updated successfully")
                        s=input("Do you want to update more records,Y or N:")
                else:
                        print("Wrong Item Code")
                        print()
                        print("Try Again")
                Submenu()
#                               Item menu Item List
def Item_List():
        df=pd.read_csv("Item.csv")
        print(df)
        Submenu()
#                                     Item Menu
def Submenu():
    print("          Item MENU           ")
    print("---------------------------------")
    print("      1-Add a new Item          ")
    print("      2-Delete an Item")
    print("      3-Update an Item")
    print("      4-Show List of Items")
    print("      5-Back")
    y=int(input("Enter your choice (1-5) : "))
    if y==1:
        Add_Items()
        Submenu()
    elif y==2:
        Delete_Item()
        Submenu()
    elif y==3:
            Update_Item()
            Submenu()
    elif y==4:
        Item_List()
        Submenu()
    else:
        print("back to main menu")
        print()
        Menu()

#                                     Custumer Details
def Submenu1():
        print("          Customers Menu           ")
        print("----------------------------------------")
        print("      1-Add Customer's Details")
        print("      2-Delete Customer's Details")
        print("      3-Update customer's Details")
        print("      4-Show_Cust Details")
        print("      5-Back")
        x=int(input("Enter your choice(1-5) : "))
        if x==1:
                Add_Customer()
                Submenu1()
        elif x==2:
                Delete_customer()
                Submenu1()
        elif x==3:
                Update_Customer()
                Submenu()
        elif x==4:
                Cust_List()
                Submenu1()
        else: 
           print("Back to Main Menu")
           print()
           Menu()

#                                     Sales Analysis
def Submenu2():
        print("        Analysis Menu         ")
        print("----------------------------------")
        print("       1-Sales Graph")
        print("       2-Monthwise Sales Graph")
        print("       3-Yearwise Sales Graph")
        print("       4-Back")
        w=int(input("Enter your choice (1-4) : "))
        if w==1:
                Sales_Graph()
                Submenu2()
        elif w==2:
                Monthwise_Graph()
                Submenu2()
        elif w==3:
                Yearwise_Graph()
                Submenu2()
        else:
                print("back to Main Menu")
                print()
                Menu()
#                                     Bill Menu
def Submenu3():
        print("        Bill Menu")
        print("----------------------------------")
        print("        1-Add Bill")
        print("        2-Delete Bill")
        
        print("        3-Back")
        i=int(input("Enter your choice(1-4):"))
        if i==1:
                Add_Bill()
                Submenu3()
        elif i==2:
                Delete_Bill()
                Submenu3()
        else:
            print("Going back to main menu")
            print()
            Menu()
#                                     Main Menu
def Menu():
    print()
    print("               Welcome To NavJeevan SuperStore              ")
    print("______________________________________________________________")
    print("          1- Item")
    print("          2- Customers_Details")
    print("          3- Bill")
    print("          4- Sales_Analysis")
    print("          5- Exit")
    z=int(input("Enter your choice(1-5) : "))
    print()
    if z==1:
        Submenu()
    elif z==2:
        Submenu1()
    elif z==3:
        Submenu3()
    elif z==4:
        Submenu2()
    else:
        print("Thank you visit again")
Menu()
