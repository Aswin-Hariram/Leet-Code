WITH agg AS (
    SELECT
        customer_id,
        COUNT(*) AS total_txn,
        SUM(CASE WHEN transaction_type = 'refund' THEN 1 ELSE 0 END) AS refund_count,
        SUM(CASE WHEN transaction_type = 'purchase' THEN 1 ELSE 0 END) AS purchase_count,
        DATEDIFF(MAX(transaction_date), MIN(transaction_date)) AS active_days
    FROM customer_transactions
    GROUP BY customer_id
)
SELECT
    customer_id
FROM agg
WHERE purchase_count >= 3
  AND active_days >= 30
  AND refund_count / total_txn < 0.2
ORDER BY customer_id;
