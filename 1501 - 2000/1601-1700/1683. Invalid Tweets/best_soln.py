import pandas as pd

def invalid_tweets(tweets: pd.DataFrame) -> pd.DataFrame:
    tweets['valid'] = tweets.content.apply(lambda x: len(x) > 15)
    return tweets.loc[tweets.valid,['tweet_id']]