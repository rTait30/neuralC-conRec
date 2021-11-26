
#import pandas as pd
import yahoo-finance as yf

#msft = yfinance.Ticker("MSFT")
#print(msft)

data = yf.download("SPY AAPL", start="2017-01-01", end="2017-04-30")

print (data)
"""
returns
<yfinance.Ticker object at 0x1a1715e898>
"""

# get stock info
#msft.info

"""
returns:
{
 'quoteType': 'EQUITY',
 'quoteSourceName': 'Nasdaq Real Time Price',
 'currency': 'USD',
 'shortName': 'Microsoft Corporation',
 'exchangeTimezoneName': 'America/New_York',
  ...
 'symbol': 'MSFT'
}
"""

# get historical market data, here max is 5 years.
#msft.history(period="max")
