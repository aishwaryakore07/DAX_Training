using Microsoft.EntityFrameworkCore;

namespace Login_Page.Models
{
    public class DataContext : DbContext
    {
        public DbSet<User> Users { get; set; }
    }
}
