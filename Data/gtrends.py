from pytrends.request import TrendReq

pytrends = TrendReq(hl='en-US')

all_keywords = ['Tesla']
pytrends.build_payload(all_keywords, cat=0, timeframe='today 5-y', geo='', gprop='')

pytrends.interest_over_time()

