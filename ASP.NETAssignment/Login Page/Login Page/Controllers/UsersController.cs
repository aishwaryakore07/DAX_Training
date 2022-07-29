using Microsoft.AspNetCore.Mvc;
using Login_Page.Models;
namespace Login_Page.Controllers
{
    public class UsersController : Controller
    {
        private DataContext db = new DataContext();
        public IActionResult Index()
        {
            return View(db.Users.ToList());
        }

        public IActionResult Register()
        {
            return View();
        }

        [HttpPost]
        public IActionResult Register(User usr)
        {
            if (ModelState.IsValid)
            {
                db.Users.Add(usr);
                db.SaveChanges();
                return RedirectToAction("Index");
            }
            else
            {
                ModelState.AddModelError("", "SOme Error Occurred");
            }
            return View(usr);
        }
        
    }
}
