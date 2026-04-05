# example_query.py
import dns.resolver  # pip install dnspython

# List of domains to query
domains = ["www.google.com", "www.example.com", "www.wikipedia.org"]

resolver = dns.resolver.Resolver()
resolver.timeout = 2
resolver.lifetime = 2

print("DNS Lookup Results:\n")
for domain in domains:
    try:
        answers = resolver.resolve(domain, 'A')  # Query IPv4 (A) records
        for rdata in answers:
            print(f"{domain} → {rdata.address} (TTL: {answers.rrset.ttl}s)")
    except Exception as e:
        print(f"{domain} → Error: {e}")


#Queries each domain for its A record 
#prints IP + TTL