# Design and Draft

three characters
- customer
- saler
- admin

# GUI and Usages

## Login Menu
```
# Login #
*===============*=================*================*=========*
| 1. User Login | 2. User Sign Up | 3. Admin Login | 4. Exit |
*===============*=================*================*=========*

Choose your operation: #
User Name: #
Passward: # 

*** Succeed! ***
*** Fail, check your info! ***
```

## User Main Menu

customer part:
```
# Main Menu #
*==========*===========*================*===========*=========*============*
| 1. items | 2. search | 3. your orders | 4. logout | 5. help | 6. account |
*==========*===========*================*===========*=========*============*

Choose your operation: #
```

<!-- saler part: -->
user part:
```
# Main Menu #
*======================*==============*===========*===========*===========*=========*============*
| 1. manage your items | 2. all items | 3. search | 4. orders | 5. logout | 6. help | 7. account |
*======================*==============*===========*===========*===========*=========*============*

Choose your operation: #
```

admin part:
```
# Main Menu #
*=================*===========*==================*=================*===========*
| 1. manage items | 2. search | 3. manage orders | 4. manage users | 5. logout |
*=================*===========*==================*=================*===========*

Choose your operation: #
```

## Item List
```
******************************************************
ITEM_ID  NAME   PRICE   DATE        SALER_ID    STATUS
M00001  数据库   50     2022-01-01   U00001       2
M00002
...
******************************************************
```

## Order List
```
**************************************************************
ORDER_ID      ITEM_ID  PAID  DATE        CUSTOMER_ID  SALER_ID
T00001        M00001   10    2021-03-14  U00001       U00002
...
**************************************************************
```

## Search
```
Enter Item Name: #

******************************************************
ITEM_ID  NAME   PRICE   DATE        SALER_ID    STATUS
M00001  数据库   50     2022-01-01   U00001       2
...
******************************************************

*****************************
NOT FOUND! Back to main menu. 
*****************************
```

## Manage Items
```
Type your operation on Items: 
#

VIEW ALL
********************************************
ITEM_ID  NAME   PRICE   DATE        SALER_ID    STATUS
M00001  数据库   50     2022-01-01   U00001       2
...
********************************************

VIEW [ITEM_ID]
********************************************
ITEM_ID: [ITEM_ID]
NAME: XXX
PRICE: 50
DESCRIPTION: [NOTES]
********************************************

DELETE [ITEM_ID]
********************************************
ITEM_ID: [ITEM_ID]
NAME: XXX
PRICE: 50
DESCRIPTION: [NOTES]
********************************************
[confirm] delete?(y/n): #

****Succeed****
****Canceled****

*******************************
FAILED, the item is not exist. 
*******************************

POST
********************************************
enter the following info:
Name: xxxx
Price: 1500
Description: xxxxxxxx
********************************************
[confirm] post?(y/n): #

****Succeed****
****Canceled****

DOWN [ITEM_ID]
********************************************
ITEM_ID: [ITEM_ID]
NAME: XXX
PRICE: 50
DESCRIPTION: [NOTES]
********************************************
[confirm] take down?(y/n): #

****Succeed****
****Canceled****

MODIFY [ITEM_ID]
********************************************
Enter the new info, or you should press ENTER to pass it!
NAME: XXXx
PRICE: 500
DESCRIPTION: [NEW-NOTES]
********************************************

********************************************
ITEM_ID: [ITEM_ID]
NAME: XXXx
PRICE: 500
DESCRIPTION: [NEW-NOTES]
********************************************
[confirm] change?(y/n): #

****Succeed****
****Canceled****
```
details:
- {down | DOWN | 1} \[ITEM_ID\] : take down an item
- {view | VIEW | 2} \[all | ALL | ITEM_ID\] : show all items
- {post | POST | 3} : post a new item
- {modify | MODIFY | 4} \[ITEM_ID\]: modify the info of ITEM_ID

## Manage Users
```
Type your operation on Users: 
#

VIEW ALL
********************************************
USER_ID  NAME   TEL              ADDRESS        BALANCE
U00001   张三   13500000000     XXXXXXXXXXXXX    100.0
...
********************************************

VIEW [USER_ID]
********************************************
ITEM_ID: [USER_ID]
NAME: XXX
TEL: 13500000000
ADDRESS: XXXXXXXXXXXXX
BALANCE: 100.0
********************************************

DELETE [USER_ID]
********************************************
ITEM_ID: [USER_ID]
NAME: XXX
TEL: 13500000000
ADDRESS: XXXXXXXXXXXXX
BALANCE: 100.0
********************************************
[confirm] delete?(y/n): #

****Succeed****
****Canceled****

*******************************
FAILED, the user is not exist. 
*******************************

DOWN [USER_ID]
********************************************
ITEM_ID: [USER_ID]
NAME: XXX
TEL: 13500000000
ADDRESS: XXXXXXXXXXXXX
BALANCE: 100.0
********************************************
[confirm] take down?(y/n): #

****Succeed****
****Canceled****
```
details:
- {view | VIEW | 1} \[all | ALL | USER_ID\] : show all users
- {delete | DELETE | del | 2} \[USER_ID\] : delete a user

## Manage Orders


## Account
```
********************************************
uName: uxxx
TEL: 12345678901
ADDRESS: XXXXXXX
BALANCE: 550.0
********************************************

*=========*=========*=============*
| 1. menu | 2. edit | 3. recharge |
*=========*=========*=============*
Type your operation on Users: 
#

2. edit
********************************************
Enter the new info, or you should press ENTER to pass it!
uName: new_uxxx
TEL: 12345678901
ADDRESS: newXXXXXXX
********************************************
[confirm] save?(y/n): #

****Succeed****
****Canceled****

3. recharge
********************************************
Recharge amount: #
********************************************
[confirm] (y/n): #

****Succeed****
****Canceled****
```

# Data

## User
```
********************************************************
USER_ID  NAME   TEL              ADDRESS        BALANCE
U00001   张三   13500000000     XXXXXXXXXXXXX    100.0
...
********************************************************
```
details:
- split("\t")
- endWith("\n")
- USER_ID : char(6)
- PASSWARD : char(20)
- NAME : char(40)
- TEL : char(11)
- ADDRESS : char(256)
- BALANCE : float char(5)
- PRIVILEGE: 0 (not avaliable), 1 (normal), 2(admin)

## Item
```
******************************************************
ITEM_ID  NAME   PRICE   DATE        SALER_ID    STATUS
M00001  数据库   50     2022-01-01   U00001       2
M00002   ...
...
******************************************************
```
details:
- split("\t")
- endWith("\n")
- ITEM_ID : char(6)
- NAME : char(40)
- PRICE : float
- DESCRIPTION : char(256)
- SALER_ID : char(6)
- DATE : char(10) "YYYY-MM-DD"
- STATUS : int, 1(sold out), 2(selling), 3(took down)

## Order
```
**************************************************************
ORDER_ID      ITEM_ID  PAID  DATE        CUSTOMER_ID  SALER_ID
T00001        M00001   10    2021-03-14  U00001       U00002
...
**************************************************************
```
details:
- split("\t")
- endWith("\n")
- ORDER_ID : char(6)
- ITEM_ID : char(6)
- PAID : float
- DATE : char(10) "YYYY-MM-DD"
- CUSTOMER_ID : char(6)
- SALER_ID : char(6)
- STATUS : int, 1 (pending), 2 (finish)

## Page && Code

```

```