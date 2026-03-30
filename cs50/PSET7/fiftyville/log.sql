-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Check descriptions of the crime scene reports at given location and time
SELECT description FROM crime_scene_reports WHERE year = "2021" AND month = "7" AND day = "28" AND street = "Humphrey Street";
-- Check names of the witnesses who might be potential accomplice
SELECT name,transcript FROM interviews WHERE year = "2021" AND month = "7" AND day = "28";
-- There are two Eugene names in transcripts so check how many Eugenes has the town
SELECT name FROM people WHERE name = "Eugene";
-- Find three witnesses who have used the word "bakery" in their interview
SELECT name, transcript FROM interviews WHERE year = "2021" AND month = "7" AND day = "28" AND transcript LIKE "%bakery%";
--witnesses are Ruth Eugene and Raymond

--Eugene gave clues that thief was withdrawing mony from ATM on Leggett Street. Check account number of the people who did the transaction at the same time.
SELECT account_number, amount FROM atm_transactions WHERE year = "2021" AND month = "7" AND day = "28" AND atm_location = "Leggett Street" AND transaction_type = "withdraw";
--Find names of people associating with account numbers
SELECT name, atm_transactions.amount FROM people JOIN bank_accounts ON people.id = bank_accounts.person_id JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number WHERE atm_transactions.year = "2021" AND atm_transactions.month = "7" AND atm_transactions.day = "28" AND atm_transactions.atm_location = "Leggett Street" AND atm_transactions.transaction_type = "withdraw";
-- Raymond gave clues that the thief was talking for less than a minute on phone and asked for a ticket for first flight out of fiftyville the next day.
-- Find the airport of fiftyville
SELECT abbreviation, full_name, city FROM airports WHERE city = "Fiftyville";
-- Find the flights that took place the next day
SELECT flights.id, full_name, city, flights.hour, flights.minute FROM airports JOIN flights ON airports.id = flights.destination_airport_id WHERE flights.origin_airport_id IN (SELECT id FROM airports WHERE city = "Fiftyville") AND flights.year = "2021" AND flights.month = "7" AND flights.day = "29" ORDER BY flights.hour, flights.minute;
-- First flight is to New York City so the thief is at NYC
-- Check the list of passengers of that flight
SELECT passengers.flight_id, name, passengers.passport_number, passengers.seat FROM people JOIN passengers ON people.passport_number = passengers.passport_number JOIN flights ON passengers.flight_id = flights.id WHERE flights.year = "2021" AND flights.month = "7" AND flights.day = "29" AND flights.hour = "8" AND flights.minute = "20" ORDER BY passengers.passport_number;
-- Check the phonecalls under one minute that took place on the day of theft
SELECT name, phone_calls.duration FROM people JOIN phone_calls ON people.phone_number = phone_calls.caller WHERE phone_calls.year = "2021" AND phone_calls.month = "7" AND phone_calls.day = "28" AND phone_calls.duration <= "60" ORDER BY phone_calls.duration;
-- Check the name of phone call receivers
SELECT name, phone_calls.duration FROM people JOIN phone_calls ON people.phone_number = phone_calls.receiver WHERE phone_calls.year = "2021" AND phone_calls.month = "7" AND phone_calls.day = "28" AND phone_calls.duration <= "60" ORDER BY phone_calls.duration;
-- Ruth gave clues that thief left the parking lot whitin 10 minutes of theft
SELECT name, bakery_security_logs.hour, bakery_security_logs.minute FROM people JOIN bakery_security_logs ON people.license_plate = bakery_security_logs.license_plate WHERE bakery_security_logs.year = "2021" AND bakery_security_logs.month = "7" AND bakery_security_logs.day = "28" AND bakery_security_logs.activity = "exit" AND bakery_security_logs.hour = "10" AND bakery_security_logs.minute >= "15" AND bakery_security_logs.minute <= "25" ORDER BY bakery_security_logs.minute;
-- Find the thief by looking for the person that exists in all 4 tables above and find the accomplice by the call receiver whom the thief has talk on phone with
