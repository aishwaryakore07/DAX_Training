using System.ComponentModel.DataAnnotations;

namespace Login_Page.Models
{
    public class User
    {
        [Key]
        public int userId { get; set; }

        [Required]
        [Display(Name = "UserName")]
        public string UserName { get; set; }

        [Required]
        [Display(Name ="Password")]
        [DataType(DataType.Password)]
        public string Password { get; set; }

        [Display(Name ="First Name")]
        public string FirstName { get; set; }

        [Display(Name ="Last Name")]
        public string LastName { get; set; }

        [Required(ErrorMessage ="email is required")]
        [Display(Name ="Email Id")]
        [DataType (DataType.EmailAddress, ErrorMessage ="Email is not valid")]
        public string Email { get; set; }

        [Display(Name ="Mobile")]
        public string Mobile { get; set; }
    }
}
