class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        email_to_name = {}
        graph = collections.defaultdict(set)
        
        for account in accounts:
            name = account[0]
            for email in account[1:]:
                graph[account[1]].add(email)
                graph[email].add(account[1])
                email_to_name[email] = name
        
        seen = set()
        sorted_accounts = []
        
        for email in graph:
            if email in seen:
                continue
            seen.add(email)
            stack = [email]
            component = []
            while stack:
                node = stack.pop()
                component.append(node)
                for other_emails in graph[node]:
                    if other_emails in seen:
                        continue
                    seen.add(other_emails)
                    stack.append(other_emails)
            sorted_accounts.append([email_to_name[email]] + sorted(component))
        
        return sorted_accounts