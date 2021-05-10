/*(1) Describe deposit.*/
DESC deposits;

/*(2) Describe borrow.*/
DESC borrows;

/*(3) List all data from table DEPOSIT.*/
SELECT * FROM deposits;

/*(4) List all data from table BORROW.*/
SELECT * FROM borrows;

/*(5) List all data from table CUSTOMERS.*/
SELECT * FROM customers;

/*(6) List all data from table BRANCH.*/
SELECT * FROM branches;

/*(7) Give account no and amount of depositors.*/
SELECT ACTNO AS "ACCOUNT NUMBER", AMOUNT AS "AMOUNT" FROM deposits;

/*(8) Give name of depositors having amount greater than 4000.*/
SELECT CNAME AS "CUSTOMER NAME" FROM deposits WHERE AMOUNT > 4000;

/*(9) Give name of customers who opened account after date '1-12-96'.*/
SELECT CNAME AS CUSTOMER ,DATE_FORMAT(ADATE, '%d-%m-%y') AS "DATE" FROM deposits;

/*(10) Find the number of branches from Delhi and Nagpur.*/
SELECT COUNT(*) FROM branches WHERE CITY = 'DELHI' OR CITY = 'NAGPUR';

/*(11) Find the number of customers from Bombay.*/
SELECT COUNT(*) FROM customers WHERE CITY = 'BOMBAY';

/*(12) Find the total amount deposited by customers.*/
SELECT SUM(AMOUNT) FROM deposits;

/*(13) Find the total amount borrowed by customers.*/
SELECT SUM(AMOUNT) FROM borrows;

/*(14) Find the name of customers from Bombay and Nagpur.*/
SELECT CNAME AS CUSTOMERS FROM customers WHERE CITY = 'BOMBAY' OR CITY = 'NAGPUR';

/*(15) Find the name of branches from Delhi, Nagpur and Banglore.*/
SELECT BNAME AS "BRANCH NAME" FROM branches WHERE CITY = 'DELHI' OR CITY = 'NAGPUR' OR CITY = 'BANGALORE';

/*(16) Find the average amount of depositor.*/
SELECT AVG(AMOUNT) AS "AVERAGE DEPOSITS"  FROM deposits;

/*(17) Give the name of depositors who has maximum balance.*/
SELECT CNAME AS "MAXIMUM DEPOSITER" FROM deposits WHERE AMOUNT = (SELECT MAX(AMOUNT) FROM deposits);

/*(18) Give the name of depositors who has minimum balance.*/
SELECT CNAME AS "MINIMUM DEPOSITER" FROM deposits WHERE AMOUNT = (SELECT MIN(AMOUNT) FROM deposits);

/*(19) To display the current date.*/
SELECT DATE_FORMAT(CURDATE(), '%d-%m-%y') AS "PRESENT DATE";

/*(20) Give name of depositors having amount greater than average amount.*/
SELECT CNAME AS CUSTOMER FROM deposits WHERE AMOUNT > (SELECT AVG(AMOUNT) FROM deposits);