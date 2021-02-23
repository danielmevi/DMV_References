# Verizon Media SSP Technical Test

Summary:
The coding task mimics elements of an advertising auction.

Logistics:
You have 7 days to complete the challenge.
Use your skills, tools, libraries and information sources that you typically use to complete a task
Zip your results and send it back with the recruitment team
Include sources, libs, outputs 

Background:
The attached JSON bid-response.json file represents a bid into the ad auction
The bid response JSON contains a seatbid which contains multiple bids
Each bid contains a bid price (field name: price) and an ad html/js markup (field name: adm)

Task:
Design and implement a solution to do the following
1. Examine the  bid-response.json and identify the important fields (e.g. seadbid, bid, price, adm)
2. Create a data structure/record that models the important fields on the bid-response.json 
3. Parse the JSON (note: using a JSON library is preferred)
4. Write the parsed data into the data structure
5. Identify the winning bid using the highest price
6. In the adm field replace all occurrences of “\n” with carriage return (not including quotes) 
7. Then replace all occurrences of “\\” with “\” (not including quotes) 
8. Write the processed output ad markup to the body of an HTML file (You can use the sample template)
9. Trace out the id and price of the winning bid

Scoring:
The marking of the solution is made on these factors
1. A correct solution
2. The C++ style applied (i.e. practices and idioms used)
3. Tests and testability
4. Code Structure and Extensibility 
5. Error Handling and Failure cases (e.g. Parse failure, Empty arrays)

FAQ:
Q: Can I use libraries?
A: Yes, this is preferred

Q: Can I use Docker?
A: Yes, if you want to

Q: Can I include a Makefile?
A: Yes

Q: The markup does not render correctly, is that a problem?
A: No, get the core functionality in place. Do not overly focus on perfect HTML/JS

Q: Do I need to create two web services one for the source bid-response.json and one for the result?
A: No, just use the filesystem as input and output.

Q: Does uses of "a data structure" imply the use a database?
A: No, use an appropriate data structure (e.g. Map, Set, List, Class/Struct etc.)


Appendix:
An advertising auction follows these steps:
A user visits a web page, in the background an ad platform initiates an auction.
The ad platform contacts bidders providing the opportunity for an advertiser 
to show an ad to the end user. The advertiser is a bidder into the auction.
The selected winning ad is displayed to the end user.
The coding challenge is to process the bids and select a winner.
